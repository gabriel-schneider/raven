//
// Created by Gabriel Schneider on 9/28/2017.
//

#ifndef RAVEN_SHADER_H
#define RAVEN_SHADER_H

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <string>
#include "Types.h"

namespace Raven {
    class Shader {
    protected:

        GLuint programId;
    public:
        const std::string &getName() const;
        void setName(const std::string &name);
    public:
        std::string name;
        void use();
        void setUniform(std::string uniformName, bool value) const;
        void setUniform(std::string uniformName, float value) const;
        void setUniform(std::string uniformName, int value) const;
        void setUniform(std::string uniformName, Matrix4 value) const;
        void setUniform(std::string uniformName, Vector3 value) const;
        void setUniform(std::string uniformName, Vector2 value) const;

        Shader(GLuint program);
    };
}


#endif //RAVEN_SHADER_H
