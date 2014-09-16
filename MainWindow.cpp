
#include <QMessageBox.h>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SettingsDialog.h"
#include "freeFunctions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_crOk( false ),
    m_lfOk( false ),
    m_sizeOfPackage( 42 ),
    m_isReadyToSend( false )
{
    ui->setupUi(this);

    m_receiver = new Receiver;

    connect( &m_timer, SIGNAL( timeout() ),
             this, SLOT( slotTimeout() ) );
    m_timer.start( 3000 );

    m_database = QSqlDatabase::addDatabase( "QSQLITE" );
    m_database.setDatabaseName( "Weighings.sqlite" );

    if ( !m_database.open() ) {
        QString message = tr( "Error: database file was not opened" );
        QMessageBox::information( this, tr( "Error" ),
                                  message );
    }

    //    QSqlQuery query( m_database );
    //    if ( !query.exec( "CREATE  TABLE \"main\".\"table\" (\"id\" INTEGER PRIMARY KEY  NOT NULL , \"name\" VARCHAR)" ) ) {
    //        QMessageBox::information( this, tr( "Error" ), tr( "Error: unable to create a table" ) );
    //    }

    m_model = new QSqlTableModel( this, m_database );
    m_model->setEditStrategy( QSqlTableModel::OnManualSubmit );
    m_model->setTable( "WeighingTable" );

    m_model->select();

    //    QSqlQuery query( m_database );
    //    if ( !query.exec( "CREATE  TABLE \"main\".\"WeighingTable\" (\"id\" INTEGER PRIMARY KEY  NOT NULL , \"date\" VARCHAR, \"weight\" DOUBLE )" ) ) {
    //        QMessageBox::information( this, tr( "Error" ), tr( "Error: unable to create a table" ) );
    //    }

    m_model->database().transaction();

    ui->tableView->setModel( m_model );
    ui->tableView->hideColumn( 0 );
    m_model->setHeaderData( 1, Qt::Horizontal, tr( "Дата и время" ) );
    m_model->setHeaderData( 2, Qt::Horizontal, tr( "Вес" ) );
}

MainWindow::~MainWindow()
{
    delete m_receiver;
    delete ui;
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog dialog;
    dialog.setModal( true );
    connect( &dialog, SIGNAL( signalSetSettings( Receiver ) ),
             this, SLOT( slotSetSettings( Receiver ) ) );
    dialog.exec();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::slotSetSettings( const Receiver &receiver )
{
    delete m_receiver;

    m_receiver = new Receiver( receiver );

    try {
        m_receiver->run();
        connect( m_receiver, SIGNAL( signalReceivedData( QByteArray ) ),
                 this, SLOT( slotReceiveData( QByteArray ) ) );
    } catch ( const PortError &e ) {
        QString message( e.what() );
        QMessageBox::information( this, tr( "Error" ), message );
        return;
    } catch( ... ) {
        QString message( "Error: unknown exception" );
        QMessageBox::information( this, tr( "Error" ), message );
        return;
    }
}

void MainWindow::slotReceiveData( const QByteArray &data )
{
    if ( !m_isReadyToSend ) {
        return;
    }

    QString strByte( data );
    QString strEnd = "0A";

    // Save package
    if ( ( strByte == strEnd ) && ( m_package.size() == m_sizeOfPackage ) ) {
        m_package.append( strByte );
        float weight = 0.0f;
        try {
            weight = getWeight( m_package );
        } catch ( const LogicError &e ) {
            return;
        }

        if ( weight > 100.0f ) {
            setDataToTable( QDateTime::currentDateTime(), weight );
            m_isReadyToSend = false;
            m_timer.start( 3000 );
        }
        m_package.clear();
        return;
    } if ( strByte == strEnd ) {
        m_package.clear();
    } else if ( m_package.size() >= m_sizeOfPackage ) {
        m_package.clear();
        return;
    } else {
        if ( strByte != strEnd ) {
            m_package.append( strByte );
        }
    }
}

void MainWindow::on_actionClear_triggered()
{
    int rowCount = m_model->rowCount();
    m_model->removeRows( 0, rowCount );
    submit();
}

void MainWindow::slotTimeout()
{
    m_isReadyToSend = true;
    m_timer.stop();
}

void MainWindow::submit()
{
    if( m_model->submitAll() ) {
        m_model->database().commit();
    } else {
        m_model->database().rollback();
        //        qDebug() << "Database Write Error" <<
        //                    "The database reported an error: " <<
        //                    m_model->lastError().text();

    }
}

void MainWindow::setDataToTable( const QDateTime &time, float weight )
{
    int rowCount = m_model->rowCount();
    if( !m_model->insertRow( rowCount ) ) {
        return;
    }

    m_model->setData( m_model->index( rowCount, 1 ), time );
    m_model->setData( m_model->index( rowCount, 2 ), weight );

    submit();
}
