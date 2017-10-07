//
// Created by Gabriel Schneider on 9/27/2017.
//



#ifndef RAVEN_APPLICATION_H
#define RAVEN_APPLICATION_H

#include "ServiceLocator.h"
#include "ServiceAware.h"
#include "WindowManager.h"
#include <vector>
#include "Object.h"

namespace Raven {

    class Application : public ServiceAware {
    private:
        double lastTime = 0;
        double updateTime = 0;
    public:
        double deltaTime = 0;
        float updateFps = 60.0;
        std::vector<Object*> objectList;
        Application(ServiceLocator &serviceLocator);
        void setup();
        void run();
    };
}


#endif //RAVEN_APPLICATION_H
