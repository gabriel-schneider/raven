//
// Created by Gabriel Schneider on 10/5/2017.
//

#include "SceneManager.h"

namespace Raven {
    Scene &SceneManager::getCurrentScene() const {
        return *currentScene;
    }

    void SceneManager::setCurrentScene(Scene &currentScene) {
        SceneManager::currentScene = &currentScene;
    }
}

