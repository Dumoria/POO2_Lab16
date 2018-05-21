/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Cop.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of a boat

Remark(s)   : -
----------------------------------------------------------------------------------------
*/
#ifndef POO2_LABO4_GOBET_THOMAS_BOAT_H
#define POO2_LABO4_GOBET_THOMAS_BOAT_H


#include <utility>
#include "Container.h"
#include "Bank.h"

class Boat : public Container {
    Bank* currentBank;

public:
    explicit Boat(std::string name) : Container(std::move(name)) {max = 2;};
    Boat(std::string name, Bank *currentBank) : Container(std::move(name)), currentBank(currentBank) {max = 2;};

    void setCurrentBank(Bank* bank);
    Bank* getCurrentBank();
    void embark(const Person& person);
    void debark(const Person& person);

    friend std::ostream& operator << (std::ostream& os, const Boat* boat);
};


#endif //POO2_LABO4_GOBET_THOMAS_BOAT_H
