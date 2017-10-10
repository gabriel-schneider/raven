//
// Created by Gabriel Schneider on 10/7/2017.
//

#include "ApplicationAware.h"

namespace Raven {
    Application *ApplicationAware::getApplication() const {
        return application;
    }

    void ApplicationAware::setApplication(Application *application) {
        this->application = application;
    }
}