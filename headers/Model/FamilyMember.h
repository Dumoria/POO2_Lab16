/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : FamilyMember.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of a family member

Remark(s)   : -
----------------------------------------------------------------------------------------
*/
#ifndef POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H
#define POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H


#include <utility>
#include "Person.h"

class FamilyMember : public Person{
public:
    FamilyMember(std::string name, Gender gender): Person(std::move(name), gender) {};
};

#endif //POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H
