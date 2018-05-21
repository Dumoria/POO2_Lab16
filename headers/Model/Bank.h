/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Cop.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of a bank

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_GOBET_THOMAS_BANK_H
#define POO2_LABO4_GOBET_THOMAS_BANK_H

#include "Container.h"

class Bank : public Container {
public:
    explicit Bank(std::string name) : Container(name) {};
    Bank(std::string name, std::initializer_list<Person> args) : Container(name, args) {};
};


#endif //POO2_LABO4_GOBET_THOMAS_BANK_H
