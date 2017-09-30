//
// Created by Gabriel Schneider on 9/28/2017.
//

#ifndef RAVEN_OBJECT_H
#define RAVEN_OBJECT_H

#include "Types.h"
#include "ServiceAware.h"

namespace Raven {

    class Object : public ServiceAware {
    public:
        glm::mat4 modelMatrix;
        Vertex* data;
        int *indices;
        float x, y, z;
        int width, height;
        unsigned int vao, vbo, ebo;
        void setup();
        void render();
    };
}


#endif //RAVEN_OBJECT_H
