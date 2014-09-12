
#include "gtest/gtest.h"
#include "IncorrectSize.h"

TEST( test001, messageTest )
{
    IncorrectSize e;

    std::string actual = e.message();
    std::string expected = "Error: incorrect size";
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
