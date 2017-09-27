//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "Application.h"

void Raven::Application::run() {

}

Raven::Application::Application(Raven::ServiceLocator &serviceLocator) {
    this->setServiceLocator(serviceLocator);
}
