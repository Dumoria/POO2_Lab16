//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_FATHER_H
#define POO2_LABO4_GOBET_THOMAS_FATHER_H

#include "FamilyMember.h"

class Father : public FamilyMember {

public:
    explicit Father(const std::string &name) : FamilyMember(name, 1) {};
};
#endif //POO2_LABO4_GOBET_THOMAS_FATHER_H
