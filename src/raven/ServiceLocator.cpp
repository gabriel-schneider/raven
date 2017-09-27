//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "ServiceLocator.h"

void Raven::ServiceLocator::set(std::string name, Raven::Service *service) {
    services[name] = service;
}

Raven::Service* Raven::ServiceLocator::get(std::string name) {
    return services.at(name);
}
