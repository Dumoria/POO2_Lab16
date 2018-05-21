//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_BOAT_H
#define POO2_LABO4_GOBET_THOMAS_BOAT_H

#include "Container.h"
#include "Bank.h"

class Boat : public Container {
    Bank* currentBank;

public:
    explicit Boat(std::string& name, Bank* currentBank) : Container(name), currentBank(currentBank), max(2) {};

    virtual void embark(const Person& person);
    virtual void debark(const Person& person);
};

#endif //POO2_LABO4_GOBET_THOMAS_BOAT_H
