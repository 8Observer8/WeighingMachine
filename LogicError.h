#ifndef LOGICERROR_H
#define LOGICERROR_H

#include <stdexcept>

class LogicError : public std::runtime_error
{
public:
    LogicError( ) :
        std::runtime_error( "" ),
        m_message( "" )
    {

    }

    virtual ~LogicError() throw()
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

#endif // LOGICERROR_H
