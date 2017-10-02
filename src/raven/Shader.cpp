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

    void Shader::setUniform(const std::string uniformName, bool value) const {
        glUniform1i(glGetUniformLocation(programId, uniformName.c_str()), (int) value);
    }

    void Shader::setUniform(const std::string uniformName, float value) const {
        glUniform1f(glGetUniformLocation(programId, uniformName.c_str()), value);
    }

    void Shader::setUniform(const std::string uniformName, int value) const {
        glUniform1i(glGetUniformLocation(programId, uniformName.c_str()), value);
    }

    void Shader::setUniform(const std::string uniformName, Matrix4 value) const {
        glUniformMatrix4fv(glGetUniformLocation(programId, uniformName.c_str()), 1, GL_FALSE, glm::value_ptr(value));
    }

    void Shader::setUniform(const std::string uniformName, Vector3 value) const {
        glUniform3f(glGetUniformLocation(programId, uniformName.c_str()), value.x, value.y, value.z);
    }

    void Shader::setUniform(const std::string uniformName, Vector2 value) const {
        glUniform2f(glGetUniformLocation(programId, uniformName.c_str()), value.x, value.y);
    }
}

