//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_BOAT_H
#define POO2_LABO4_GOBET_THOMAS_BOAT_H

#include "Container.h"

class Boat : public Container {
    unsigned short max = 2;

public:
    Boat();
    explicit Boat(unsigned short max) : max(max) {};
};

#endif //POO2_LABO4_GOBET_THOMAS_BOAT_H
