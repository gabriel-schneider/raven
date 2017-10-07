//
// Created by Gabriel Schneider on 10/7/2017.
//

#include "Camera.h"

namespace Raven {

    const Matrix4 &Camera::getViewMatrix() const {
        return viewMatrix;
    }

    void Camera::setViewMatrix(const Matrix4 &viewMatrix) {
        Camera::viewMatrix = viewMatrix;
    }
}