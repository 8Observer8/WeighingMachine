#ifndef INCORRECTSIZE_H
#define INCORRECTSIZE_H

#include <stdexcept>
#include "LogicError.h"
#include "boost/lexical_cast.hpp"

class IncorrectSize : public LogicError
{
public:
    IncorrectSize( const std::string &functionName,
                   int size ) :
        LogicError( )
    {
        std::string strSize = boost::lexical_cast<std::string>( size );
        m_message = "Error: incorrect size = " + strSize + ". Function Name: "
                "\"" + functionName + "\"";
    }
};

#endif // INCORRECTSIZE_H
