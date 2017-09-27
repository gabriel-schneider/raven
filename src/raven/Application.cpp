//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "Application.h"
#include "Render.h"

void Raven::Application::run() {
    Raven::Render *render = (Render*) serviceLocator->get("render");
    render->setup();
}

Raven::Application::Application(Raven::ServiceLocator &serviceLocator) {
    this->setServiceLocator(serviceLocator);
}
