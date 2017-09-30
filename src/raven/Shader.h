//
// Created by Gabriel Schneider on 9/28/2017.
//

#ifndef RAVEN_SHADER_H
#define RAVEN_SHADER_H

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <string>

namespace Raven {
    class Shader {
    protected:
        std::string name;
    public:
        static GLuint activeProgram;
        static Shader* activeShader;

        const std::string &getName() const;

        void setName(const std::string &name);

    public:
        GLuint programId;
        void use();
        void setBool(const std::string, bool value) const;
        void setFloat(const std::string, float value) const;
        void setInt(const std::string, int value) const;
        void setMat4(const std::string, glm::mat4 value) const;
        Shader(GLuint program);
    };
}


#endif //RAVEN_SHADER_H
