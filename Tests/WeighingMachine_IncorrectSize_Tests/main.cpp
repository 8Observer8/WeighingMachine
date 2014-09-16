
#include "gtest/gtest.h"
#include "IncorrectSize.h"
#include "boost/lexical_cast.hpp"

TEST( test001, messageTest )
{
    std::string functionName = "readData()";
    int size = 22;
    IncorrectSize e( functionName, size );
    std::string strSize = boost::lexical_cast<std::string>( size );

    std::string actual = e.message();
    std::string expected = "Error: incorrect size = " + strSize + ". Function Name: "
            "\"" + functionName + "\"";
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
