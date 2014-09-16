
#include "freeFunctions.h"


float getWeight( const QByteArray &package )
throw( IncorrectSize, EmptyError )
{
    std::string functionName = "getWeight()";

    if ( package.size() == 0) {
        throw EmptyError( functionName );
    }

    if ( package.size() != 44 ) {
        throw IncorrectSize( functionName, package.size() );
    }

    // Get ASCII weightArray
    float weight = QByteArray::fromHex( package.mid( 18, 14 ) ).toFloat();

    return weight;
}
