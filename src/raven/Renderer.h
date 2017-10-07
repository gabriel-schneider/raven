//
// Created by Gabriel Schneider on 9/27/2017.
//

#ifndef RAVEN_RENDER_H
#define RAVEN_RENDER_H

#include <glm/glm.hpp>
#include "Service.h"
#include "Types.h"
#include "Camera.h"

namespace Raven {

    class Renderer : public Service {
    protected:
        Matrix4 projectionMatrix;
    public:
        Camera *camera;

        void setProjectionMatrix(const glm::mat4 &projectionMatrix);
        const glm::mat4 &getProjectionMatrix() const;
        virtual void setup() = 0;
        virtual void render() = 0;
    };

}


#endif //RAVEN_RENDER_H
