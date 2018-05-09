//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H
#define POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H

#include "Person.h"

class FamilyMember : public Person{
public:

    FamilyMember(const std::string &name, bool gender) : Person(name, gender) {};

};

#endif //POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H
