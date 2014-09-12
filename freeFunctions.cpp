
#include "freeFunctions.h"


float getWeight( const QByteArray &package )
throw( IncorrectSize )
{
    if ( package.size() != 44 ) {
        throw IncorrectSize();
    }

    // Get ASCII weightArray
    QByteArray::fromHex( package.mid( 18, 12 ) ).toFloat();

    //QString strByte = package[3];


    float weight = 0.0f;
    return weight;
}
