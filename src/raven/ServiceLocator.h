//
// Created by Gabriel Schneider on 9/27/2017.
//



#ifndef RAVEN_SERVICELOCATOR_H
#define RAVEN_SERVICELOCATOR_H

#include <map>

namespace Raven {
    class ServiceAware;

    class ServiceLocator {
    protected:
        std::map<std::string, ServiceAware*> services;
    public:
        void set(std::string name, ServiceAware* service);
        ServiceAware* get(std::string name);
    };
}



#endif //RAVEN_SERVICELOCATOR_H
