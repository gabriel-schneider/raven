//
// Created by Gabriel Schneider on 9/28/2017.
//

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"

namespace Raven {
    Shader::Shader(GLuint program) {
        this->programId = program;
    }

    void Shader::use() {
        glUseProgram(this->programId);
    }

    const std::string &Shader::getName() const {
        return name;
    }

    void Shader::setName(const std::string &name) {
        Shader::name = name;
    }

    void Shader::setBool(const std::string name, bool value) const {
        glUniform1i(glGetUniformLocation(programId, name.c_str()), (int) value);
    }

    void Shader::setFloat(const std::string name, float value) const {
        glUniform1f(glGetUniformLocation(programId, name.c_str()), value);
    }

    void Shader::setInt(const std::string name, int value) const {
        glUniform1i(glGetUniformLocation(programId, name.c_str()), value);
    }

    void Shader::setMat4(const std::string name, glm::mat4 value) const {
        glUniformMatrix4fv(glGetUniformLocation(programId, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
    }
}

