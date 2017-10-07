//
// Created by Gabriel Schneider on 10/7/2017.
//

#ifndef RAVEN_CAMERA_H
#define RAVEN_CAMERA_H

#include "Types.h"

namespace Raven {
    class Camera {
    protected:
        Matrix4 viewMatrix;
    public:
        const Matrix4 &getViewMatrix() const;

        void setViewMatrix(const Matrix4 &viewMatrix);

    };
}


#endif //RAVEN_CAMERA_H
