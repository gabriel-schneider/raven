//
// Created by Gabriel Schneider on 9/27/2017.
//

#ifndef RAVEN_OPENGLRENDER_H
#define RAVEN_OPENGLRENDER_H

#include "render.h"

namespace Raven {
    class Render;
    class OpenGLRender : public Render {
    public:
        void setup() override;
        void render() override;
    };
}



#endif //RAVEN_OPENGLRENDER_H
