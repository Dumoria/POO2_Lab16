//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_PARENT_H
#define POO2_LABO4_GOBET_THOMAS_PARENT_H

#include "Parent.h"

class Mother : public Parent {
    bool gender = 0;

public:
    Mother(std::string name, bool gender);
};
#endif //POO2_LABO4_GOBET_THOMAS_PARENT_H
