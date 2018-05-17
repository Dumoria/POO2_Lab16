//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H
#define POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H


#include "Person.h"

class FamilyMember : public Person{

private:

    bool genre;

public:

    FamilyMember(std::string name, bool gender);

};

#endif //POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H
