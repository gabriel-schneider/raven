//
// Created by Gabriel Schneider on 9/28/2017.
//

#ifndef RAVEN_TYPES_H
#define RAVEN_TYPES_H

#include <glm/glm.hpp>



namespace Raven {
    typedef glm::vec3 Vector3;
    typedef glm::vec2 Vector2;
    typedef glm::mat4 Matrix4;
    typedef glm::mat3 Matrix3;
    struct Vertex {
        Vector3 position;
        Vector3 color;
        Vector2 uv;
    };
}

#endif //RAVEN_TYPES_H
