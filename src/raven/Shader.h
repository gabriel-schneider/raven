//
// Created by Gabriel Schneider on 9/28/2017.
//

#ifndef RAVEN_SHADER_H
#define RAVEN_SHADER_H

#include <GL/gl.h>
#include <string>

namespace Raven {
    class Shader {
    protected:
        GLuint programId;
    public:
        void use();
        void setBool(const std::string, bool value) const;
        void setFloat(const std::string, float value) const;
        void setInt(const std::string, int value) const;
        Shader(GLuint program);
    };
}


#endif //RAVEN_SHADER_H
