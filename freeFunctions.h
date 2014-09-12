#ifndef FREEFUNCTIONS_H
#define FREEFUNCTIONS_H

#include <QByteArray>
#include "IncorrectSize.h"

float getWeight( const QByteArray &package )
throw( IncorrectSize );

#endif // FREEFUNCTIONS_H
