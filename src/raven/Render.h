//
// Created by Gabriel Schneider on 9/27/2017.
//

#ifndef RAVEN_RENDER_H
#define RAVEN_RENDER_H

#include "Service.h"

namespace Raven {

    class Render : public Service {
    public:
        virtual void setup() = 0;
        virtual void render() = 0;
    };

}


#endif //RAVEN_RENDER_H
