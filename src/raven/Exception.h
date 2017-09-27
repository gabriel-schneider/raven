//
// Created by Gabriel Schneider on 9/27/2017.
//



#ifndef RAVEN_EXCEPTION_H
#define RAVEN_EXCEPTION_H

#include <exception>
#include <stdexcept>

namespace Raven {
    class Exception : public std::runtime_error {
    public:
        Exception(const std::string &__arg);

    };
}



#endif //RAVEN_EXCEPTION_H
