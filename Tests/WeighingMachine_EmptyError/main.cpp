
#include "gtest/gtest.h"
#include "EmptyError.h"

TEST( test001, messageTest )
{
    std::string functionName = "readData";
    EmptyError e( functionName );

    std::string actual = e.message();
    std::string expected = "Error: empty argument in the function "
            "\"" + functionName + "\"";
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
