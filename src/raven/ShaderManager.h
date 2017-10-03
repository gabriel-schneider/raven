//
// Created by Gabriel Schneider on 9/28/2017.
//

#ifndef RAVEN_SHADERMANAGER_H
#define RAVEN_SHADERMANAGER_H

#include <glad/glad.h>
#include <string>
#include <map>
#include "ServiceAware.h"

namespace Raven {
    class Shader;
    class ShaderManager : public ServiceAware {
    protected:
        std::string shaderDirectory;
        Shader* activeShader;
    public:
        Shader *getActiveShader() const;

    protected:
        GLuint loadShader(GLenum type, std::string filename);

    public:
        std::map<std::string, Shader*> shaders;
        ShaderManager(std::string shaderDirectory);
        Shader& get(std::string name) const;
        const std::string &getShaderDirectory() const;
        void setShaderDirectory(const std::string &shaderDirectory);
        bool createShader(std::string name, std::string vertexFilename, std::string fragmentFilename);
        bool deleteShader(std::string name);
        void use(std::string shader);

    };
}



#endif //RAVEN_SHADERMANAGER_H
