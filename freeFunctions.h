#ifndef FREEFUNCTIONS_H
#define FREEFUNCTIONS_H

#include <QByteArray>
#include "IncorrectSize.h"
#include "EmptyError.h"

float getWeight( const QByteArray &package )
throw( IncorrectSize, EmptyError );

#endif // FREEFUNCTIONS_H
