#ifndef EMPTYERROR_H
#define EMPTYERROR_H

#include "LogicError.h"

class EmptyError : public LogicError
{
public:
    EmptyError( const std::string &functionName )
    {
        m_message = "Error: empty argument in the function "
                "\"" + functionName + "\"";
    }
};

#endif // EMPTYERROR_H
