//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "Renderer.h"

const glm::mat4 &Raven::Renderer::getProjectionMatrix() const {
    return projectionMatrix;
}

void Raven::Renderer::setProjectionMatrix(const glm::mat4 &projectionMatrix) {
    Renderer::projectionMatrix = projectionMatrix;
}
