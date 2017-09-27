//
// Created by Gabriel Schneider on 9/27/2017.
//



#ifndef RAVEN_APPLICATION_H
#define RAVEN_APPLICATION_H

#include "ServiceLocator.h"
#include "ServiceAware.h"
#include "WindowManager.h"

namespace Raven {

    class Application : public ServiceAware {
    public:
        Application(ServiceLocator &serviceLocator);
        void setup();
        void run();
    };
}


#endif //RAVEN_APPLICATION_H
