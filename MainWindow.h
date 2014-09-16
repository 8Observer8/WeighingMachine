#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QTimer>
#include <QSqlTableModel>
#include <QDateTime>
#include "Receiver.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSettings_triggered();
    void on_actionExit_triggered();
    void slotReceiveData( const QByteArray &data );
    void slotSetSettings( const Receiver &receiver );
    void on_actionClear_triggered();
    void slotTimeout();

private:
    void submit();
    void setDataToTable( const QDateTime &time,
                         float weight );

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_database;
    QSqlTableModel *m_model;
    Receiver *m_receiver;
    bool m_crOk;
    bool m_lfOk;
    QByteArray m_package;
    const int m_sizeOfPackage;
    QTimer m_timer;
    bool m_isReadyToSend;
};

#endif // MAINWINDOW_H
