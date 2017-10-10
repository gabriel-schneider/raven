//
// Created by Gabriel Schneider on 9/27/2017.
//



#ifndef RAVEN_APPLICATION_H
#define RAVEN_APPLICATION_H



#include <vector>
#include "ApplicationAware.h"
#include "WindowManager.h"
#include "Object.h"
#include "Renderer.h"
#include "SceneManager.h"
#include "ShaderManager.h"
#include "OpenGLRenderer.h"

namespace Raven {

    class Application {
    protected:
        double lastTime = 0;
        double updateTime = 0;
        ShaderManager *shaderManager;
        WindowManager *windowManager;
        SceneManager *sceneManager;
        OpenGLRenderer *renderer;

    public:
        double deltaTime = 0;
        float updateFps = 60.0;

        void setup();
        void run();

        ShaderManager *getShaderManager() const;
        void setShaderManager(ShaderManager *shaderManager);
        WindowManager *getWindowManager() const;
        void setWindowManager(WindowManager *windowManager);
        SceneManager *getSceneManager() const;
        void setSceneManager(SceneManager *sceneManager);
        Renderer *getRenderer() const;
        void setRenderer(OpenGLRenderer *renderer);
    };
}


#endif //RAVEN_APPLICATION_H
