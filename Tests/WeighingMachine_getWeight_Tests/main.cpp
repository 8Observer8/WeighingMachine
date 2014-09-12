
#include <QByteArray>
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( test001, onePackageTest )
{
    QByteArray package = "399249FE39924955"
            "2d20202031332e35FE3992490D0A";

    float actual;
    ASSERT_NO_THROW( {
                         actual = getWeight( package );
                     } );

    float expected = 13.5f;

    float delta = 0.001;
    ASSERT_NEAR( expected, actual, delta );
}

TEST( test002, incorrectSizeTest )
{
    QByteArray package = "399249FE39924955";

    ASSERT_THROW( {
                      getWeight( package );
                  }, IncorrectSize );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
