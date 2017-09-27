//
// Created by Gabriel Schneider on 9/27/2017.
//



#ifndef RAVEN_SERVICELOCATOR_H
#define RAVEN_SERVICELOCATOR_H

#include <map>
#include "Service.h"

namespace Raven {

    class ServiceLocator {
    protected:
        std::map<std::string, Service*> services;
    public:
        void set(std::string name, Service* service);
        Service* get(std::string name);
    };
}



#endif //RAVEN_SERVICELOCATOR_H
