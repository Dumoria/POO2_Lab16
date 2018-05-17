/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Child.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of a child

Remark(s)   : -
----------------------------------------------------------------------------------------
*/


#ifndef POO2_LABO4_GOBET_THOMAS_CHILD_H
#define POO2_LABO4_GOBET_THOMAS_CHILD_H


#include "FamilyMember.h"


class Child : public FamilyMember{

public:

    Child(std::string name, bool gender): FamilyMember(name, gender){

    }


};
#endif //POO2_LABO4_GOBET_THOMAS_CHILD_H
