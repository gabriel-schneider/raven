//
// Created by Gabriel Schneider on 9/27/2017.
//

#ifndef RAVEN_APPLICATIONINTERFACE_H
#define RAVEN_APPLICATIONINTERFACE_H

#include "ServiceLocator.h"

namespace Raven {
    class Application {
    private:
        ServiceLocator *serviceLocator;
    public:
        Application(ServiceLocator &serviceLocator);
        ServiceLocator& getServiceLocator();
        void setServiceLocator(ServiceLocator &serviceLocator);
        void run();


    };
}


#endif //RAVEN_APPLICATIONINTERFACE_H
