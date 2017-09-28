//
// Created by Gabriel Schneider on 9/28/2017.
//

#ifndef RAVEN_SHADERMANAGER_H
#define RAVEN_SHADERMANAGER_H

#include <GL/GL.h>
#include <string>
#include <map>

namespace Raven {
    class Shader;
    class ShaderManager {
    protected:
        std::map<std::string, Shader*> shaders;
        std::string shaderDirectory;
        GLuint loadShader(GLenum type, const std::string filename);
    public:
        ShaderManager(std::string shaderDirectory);
        const std::string &getShaderDirectory() const;
        void setShaderDirectory(const std::string &shaderDirectory);
        bool createShader(const std::string name, const std::string vertexFilename, const std::string fragmentFilename);
        bool deleteShader(const std::string name);
    public:

    };
}



#endif //RAVEN_SHADERMANAGER_H
