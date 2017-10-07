//
// Created by Gabriel Schneider on 10/5/2017.
//

#ifndef RAVEN_SCENEMANAGER_H
#define RAVEN_SCENEMANAGER_H

#include "Scene.h"

namespace Raven {
    class SceneManager : public ApplicationAware {
    protected:
        Scene *currentScene;
    public:
        Scene &getCurrentScene() const;
        void setCurrentScene(Scene &currentScene);
    };
}


#endif //RAVEN_SCENEMANAGER_H
