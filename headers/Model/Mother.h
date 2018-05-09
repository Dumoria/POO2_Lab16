//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_MOTHER_H
#define POO2_LABO4_GOBET_THOMAS_MOTHER_H

#include "FamilyMember.h"

class Mother : public FamilyMember {

public:
    explicit Mother(const std::string &name) : FamilyMember(name, 0) {};
};
#endif //POO2_LABO4_GOBET_THOMAS_MOTHER_H
