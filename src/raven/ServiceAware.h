//
// Created by Gabriel Schneider on 9/27/2017.
//



#ifndef RAVEN_SERVICEAWARE_H
#define RAVEN_SERVICEAWARE_H

#include "ServiceLocator.h"

namespace Raven {

    class ServiceAware {
    protected:
        ServiceLocator *serviceLocator;
    public:
        ServiceLocator& getServiceLocator();
        void setServiceLocator(ServiceLocator &serviceLocator);
    };

}



#endif //RAVEN_SERVICEAWARE_H
