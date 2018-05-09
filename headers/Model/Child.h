//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_CHILD_H
#define POO2_LABO4_GOBET_THOMAS_CHILD_H

#include <utility>
#include "FamilyMember.h"

class Child : public FamilyMember{

public:
    Child(const std::string &name, bool gender) : FamilyMember(name, gender), _canDrive(false) {};

};
#endif //POO2_LABO4_GOBET_THOMAS_CHILD_H
