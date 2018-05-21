//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_BANK_H
#define POO2_LABO4_GOBET_THOMAS_BANK_H

#include "Container.h"

class Bank : public Container {
public:
    Bank(std::string& name) : Container(name) {};
    Bank(std::string& name, std::initializer_list<Person> args) : Container(name, args) {};
};

#endif //POO2_LABO4_GOBET_THOMAS_BANK_H
