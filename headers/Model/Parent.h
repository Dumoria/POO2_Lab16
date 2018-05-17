//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_PARENT_H
#define POO2_LABO4_GOBET_THOMAS_PARENT_H

#include "FamilyMember.h"

class Parent : public FamilyMember{

public:

    Parent(std::string name, bool gender);


    bool canDrive(){
        return true;
    }

    bool isParent(){
        return true;
    }

    bool isChild(){
        return false;
    }
};
#endif //POO2_LABO4_GOBET_THOMAS_PARENT_H
