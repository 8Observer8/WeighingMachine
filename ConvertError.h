#ifndef CONVERTERROR_H
#define CONVERTERROR_H

#include "LogicError.h"

class ConvertError : public LogicError
{
public:
    ConvertError( const std::string &functionName )
    {
        m_message = "Error: unable to convert. Function Name: "
                "\"" + functionName + "\"";
    }
};

#endif // CONVERTERROR_H
