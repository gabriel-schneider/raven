//
// Created by Gabriel Schneider on 10/5/2017.
//

#ifndef RAVEN_DUMMYOBJECT_H
#define RAVEN_DUMMYOBJECT_H

#include "raven/Object.h"

class DummyObject : public Raven::Object {
public:
    void update() override;
};


#endif //RAVEN_DUMMYOBJECT_H
