//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_THIEF_H
#define POO2_LABO4_GOBET_THOMAS_THIEF_H

#include "Person.h"

class Thief : public Person{

public:
    Thief(const std::string &name, bool gender) : Person(name, gender), _canDrive(false) {};
};


#endif //POO2_LABO4_GOBET_THOMAS_THIEF_H
