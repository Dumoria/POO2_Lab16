//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_DAUGHTER_H
#define POO2_LABO4_GOBET_THOMAS_DAUGHTER_H

#include "Child.h"

class Daughter : public Child {

public:
    explicit Daughter(const std::string &name) : Child(name, 0) {};
};
#endif //POO2_LABO4_GOBET_THOMAS_DAUGHTER_H
