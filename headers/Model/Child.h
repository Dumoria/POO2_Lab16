//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_CHILD_H
#define POO2_LABO4_GOBET_THOMAS_CHILD_H

#include "FamilyMember.h"

class Child : public FamilyMember{
    bool _canDrive = false;

public:

    Child(std::string name, bool gender);

};
#endif //POO2_LABO4_GOBET_THOMAS_CHILD_H
