//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "Application.h"

Raven::ServiceLocator& Raven::Application::getServiceLocator() {
    return *serviceLocator;
}

void Raven::Application::setServiceLocator(Raven::ServiceLocator &serviceLocator) {
    Application::serviceLocator = &serviceLocator;
}

void Raven::Application::run() {

}

Raven::Application::Application(Raven::ServiceLocator &serviceLocator) {
    this->setServiceLocator(serviceLocator);
}
