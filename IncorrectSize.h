#ifndef INCORRECTSIZE_H
#define INCORRECTSIZE_H

#include <stdexcept>
#include "LogicError.h"

class IncorrectSize : public LogicError
{
public:
    IncorrectSize( ) :
        LogicError( )
    {
        m_message = "Error: incorrect size";
    }

    virtual ~IncorrectSize() throw()
    {

    }

    virtual const char *what() const throw()
    {
        return m_message.c_str();
    }

    std::string message() const
    {
        return m_message;
    }

public:
    std::string m_message;
};

#endif // INCORRECTSIZE_H
