//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "ServiceAware.h"

namespace Raven {
    ServiceLocator &Raven::ServiceAware::getServiceLocator() {
        return *serviceLocator;
    }

    void ServiceAware::setServiceLocator(Raven::ServiceLocator &serviceLocator) {
        this->serviceLocator = &serviceLocator;
    }
}

