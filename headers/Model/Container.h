//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_CONTAINER_H
#define POO2_LABO4_GOBET_THOMAS_CONTAINER_H

#include <list>;
#include "Person.h"

class Container {
    std::list<Person>;
    unsigned short max;

public:
    virtual ~Container();
};

#endif //POO2_LABO4_GOBET_THOMAS_CONTAINER_H
