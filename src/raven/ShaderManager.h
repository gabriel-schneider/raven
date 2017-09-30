//
// Created by Gabriel Schneider on 9/28/2017.
//

#ifndef RAVEN_SHADERMANAGER_H
#define RAVEN_SHADERMANAGER_H

#include <GL/GL.h>
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
        GLuint loadShader(GLenum type, const std::string filename);
    public:
        long getCurrentShader() const;

    public:
        std::map<std::string, Shader*> shaders;
        ShaderManager(std::string shaderDirectory);
        Shader& get(const std::string name) const;
        const std::string &getShaderDirectory() const;
        void setShaderDirectory(const std::string &shaderDirectory);
        bool createShader(const std::string name, const std::string vertexFilename, const std::string fragmentFilename);
        bool deleteShader(const std::string name);
        void use(const std::string shader);


    };
}



#endif //RAVEN_SHADERMANAGER_H
