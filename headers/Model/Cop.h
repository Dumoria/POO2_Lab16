/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Cop.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of a cop

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_GOBET_THOMAS_COP_H
#define POO2_LABO4_GOBET_THOMAS_COP_H


#include <utility>
#include "Person.h"


class Cop : public Person{

public:
    explicit Cop(std::string name): Person(std::move(name)) {_canDrive = true;};

};

#endif //POO2_LABO4_GOBET_THOMAS_COP_H
