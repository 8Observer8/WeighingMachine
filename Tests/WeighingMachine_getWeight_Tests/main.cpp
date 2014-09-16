
#include <QByteArray>
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( test001, normalTest )
{
    QByteArray package = "399249FE39924955"
            "2d20202031332e35FE3992490D0A";

    float actual;
    ASSERT_NO_THROW( {
                         actual = getWeight( package );
                     } );

    float expected = 13.5f;

    float delta = 0.1;
    ASSERT_NEAR( expected, actual, delta );
}

TEST( test002, incorrectSizeTest )
{
    QByteArray package = "9249FE39924955"
            "2d20202031332e35FE3992490D0A";

    ASSERT_THROW( {
                      getWeight( package );
                  }, IncorrectSize );
}

TEST( test003, incorrectSizeTest )
{
    QByteArray package = "32329249FE39924955"
            "2d2020202031332e35FE92490D0A";

    ASSERT_THROW( {
                      getWeight( package );
                  }, IncorrectSize );
}

TEST( test005, emptyErrorTest )
{
    QByteArray package;

    ASSERT_THROW( {
                      getWeight( package );
                  }, EmptyError );
}

TEST( test006, onePackageTest )
{
    QByteArray package = "53542C47532C30BE"
            "2C2020202020202030206B670D0A";

    float actual;
    ASSERT_NO_THROW( {
                         actual = getWeight( package );
                     } );

    float expected = 0.0f;

    float delta = 0.1;
    ASSERT_NEAR( expected, actual, delta );
}

TEST( test007, onePackageTest )
{
    QByteArray package = "53542C47532C30BE"
            "2C2020202031303030206B670D0A";

    float actual;
    ASSERT_NO_THROW( {
                         actual = getWeight( package );
                     } );

    float expected = 1000.0f;

    float delta = 0.1;
    ASSERT_NEAR( expected, actual, delta );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
