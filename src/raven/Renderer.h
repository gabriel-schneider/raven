//
// Created by Gabriel Schneider on 9/27/2017.
//

#ifndef RAVEN_RENDER_H
#define RAVEN_RENDER_H

#include <glm/glm.hpp>
#include "Service.h"

namespace Raven {

    class Renderer : public Service {
    protected:
        glm::mat4 projectionMatrix;
    public:
        void setProjectionMatrix(const glm::mat4 &projectionMatrix);

    public:
        const glm::mat4 &getProjectionMatrix() const;

    public:
        virtual void setup() = 0;
        virtual void render() = 0;
    };

}


#endif //RAVEN_RENDER_H
