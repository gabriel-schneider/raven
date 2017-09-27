//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "Exception.h"

Raven::Exception::Exception(const std::string &__arg) : runtime_error(__arg) {}
