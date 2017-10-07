//
// Created by Gabriel Schneider on 9/28/2017.
//

#ifndef RAVEN_OBJECT_H
#define RAVEN_OBJECT_H

#include "Types.h"
#include "Texture.h"
#include "ServiceAware.h"

namespace Raven {

    class Object : public ServiceAware {
    protected:
        void updateModelMatrix();
    public:
        Texture texture;
        glm::mat4 modelMatrix;
        Vertex* data;
        unsigned int *indices;
        float x = 0, y = 0, z = 0;
        float rotx = 0, roty = 0, rotz = 0;
        int scalex = 1, scaley = 1, scalez = 1;
        int width = 32, height = 32;
        unsigned int vao, vbo, ebo;
        void setup();
        virtual void update() = 0;
        void draw();
    };
}


#endif //RAVEN_OBJECT_H
