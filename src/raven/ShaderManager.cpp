//
// Created by Gabriel Schneider on 9/28/2017.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "ShaderManager.h"
#include "Shader.h"
#include "Exception.h"


namespace Raven {
    const std::string &ShaderManager::getShaderDirectory() const {
        return shaderDirectory;
    }

    void ShaderManager::setShaderDirectory(const std::string &shaderDirectory) {
        ShaderManager::shaderDirectory = shaderDirectory;
    }

    ShaderManager::ShaderManager(std::string shaderDirectory) {
        setShaderDirectory(shaderDirectory);
    }

    bool ShaderManager::createShader(const std::string name, const std::string vertexFilename, const std::string fragmentFilename) {

        GLuint vertexId = loadShader(GL_VERTEX_SHADER, vertexFilename);
        GLuint fragmentId = loadShader(GL_FRAGMENT_SHADER, fragmentFilename);
        GLuint programId = glCreateProgram();
        glAttachShader(programId, vertexId);
        glAttachShader(programId, fragmentId);
        glLinkProgram(programId);

        GLint status = 0;
        glGetProgramiv(programId, GL_LINK_STATUS, &status);
        if (status == GL_FALSE) {
            GLint maxLength = 0;
            glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> errorLog(maxLength);
            glGetProgramInfoLog(programId, maxLength, &maxLength, &errorLog[0]);
            std::cout << "ERROR: " << std::string(errorLog.begin(), errorLog.end());
            glDeleteProgram(programId);
            throw Exception(std::string("Error at linking shader program!"));
        }

        Shader *shader = new Shader(programId);
        shaders[name] = shader;

        return true;
    }

    bool ShaderManager::deleteShader(std::string name) {
        return false;
    }

    GLuint ShaderManager::loadShader(GLenum type, const std::string filename) {
        std::ifstream file;
        std::string content;
        file.open(getShaderDirectory() + "/" + filename, std::ifstream::in);
        content.assign((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()) );

        GLuint shaderId = glCreateShader(type);
        const GLchar *source = content.c_str();
        glShaderSource(shaderId, 1, &source, nullptr);
        glCompileShader(shaderId);

        // Shader error handling
        GLint status = 0;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE) {
            GLint maxLength = 0;
            glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> errorLog(maxLength);
            glGetShaderInfoLog(shaderId, maxLength, &maxLength, &errorLog[0]);
            std::cout << std::string(errorLog.begin(), errorLog.end());

            glDeleteShader(shaderId);
            throw Exception(std::string("Error at compiling shader!"));
        }
        return shaderId;

    }
}

