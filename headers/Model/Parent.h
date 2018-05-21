/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Cop.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of a parent

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_GOBET_THOMAS_PARENT_H
#define POO2_LABO4_GOBET_THOMAS_PARENT_H


#include "FamilyMember.h"


class Parent : public FamilyMember{

public:
    Parent(const std::string &name, bool gender) : FamilyMember(name, gender), _canDrive(true) {};

};

#endif //POO2_LABO4_GOBET_THOMAS_COP_H
