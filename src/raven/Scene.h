//
// Created by Gabriel Schneider on 10/5/2017.
//

#ifndef RAVEN_SCENE_H
#define RAVEN_SCENE_H

#include "ServiceAware.h"
#include "Object.h"
#include <vector>

namespace Raven {
    class Scene : public ServiceAware {
    protected:
        std::vector<Object*> objects;
        //TODO: Add remove queue
    public:
        const std::vector<Object *> &getObjects() const;
        void add(Object& object);
        void draw();
        //void remove(Object& object);

    };
}


#endif //RAVEN_SCENE_H
