//
// Created by Gabriel Schneider on 10/5/2017.
//

#include "Scene.h"

namespace Raven {
    const std::vector<Raven::Object *> &Raven::Scene::getObjects() const {
        return objects;
    }

    void Scene::add(Object &object) {
        object.setApplication(this->application);
        objects.push_back(&object);
    }

    void Scene::draw() {
        for(Object* object : objects) {
            object->draw();
        }
    }
}