//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_BANK_H
#define POO2_LABO4_GOBET_THOMAS_BANK_H

#include "Container.h"

class Bank : public Container {
    unsigned short max = 0; // 0 si infini

public:
    Bank();
    explicit Bank(std::initializer_list<Person> args);
};


#endif //POO2_LABO4_GOBET_THOMAS_BANK_H
