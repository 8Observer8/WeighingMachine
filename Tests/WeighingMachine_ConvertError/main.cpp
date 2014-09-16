
#include "gtest/gtest.h"
#include "ConvertError.h"

TEST( test001, messageTest )
{
    std::string functionName = "readData";
    ConvertError e( functionName );

    std::string actual = e.message();
    std::string expected = "Error: unable to convert. Function Name: "
            "\"" + functionName + "\"";
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
