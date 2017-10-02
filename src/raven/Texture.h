//
// Created by Gabriel Schneider on 9/30/2017.
//

#ifndef RAVEN_TEXTURE_H
#define RAVEN_TEXTURE_H

#include <string>

namespace Raven {
    class Texture {
    protected:
        unsigned int id;
        unsigned char *data;
        int width, height, channels;
    public:
        Texture();
        bool load(std::string filename);
        void bind();
        static void unbind();
    };
}


#endif //RAVEN_TEXTURE_H
