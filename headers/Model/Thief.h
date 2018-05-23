/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Thief.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of a thief

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_GOBET_THOMAS_THIEF_H
#define POO2_LABO4_GOBET_THOMAS_THIEF_H

#include <utility>
#include "Person.h"

class Thief : public Person{

public:
    explicit Thief(std::string name) : Person(std::move(name)) {_canDrive = false;};
    Thief(std::string name, Gender gender) : Person(std::move(name), gender) {_canDrive = false;};

};


#endif //POO2_LABO4_GOBET_THOMAS_THIEF_H
