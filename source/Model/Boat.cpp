/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Controller.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Implementation of the boat

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include "../../headers/Model/Boat.h"

void Boat::setCurrentBank(Bank *bank) {
    currentBank = bank;
}

Bank* Boat::getCurrentBank() {
    return currentBank;
}

void Boat::embark(const Person& person) {
    push_back(person);
    currentBank->remove(person);
}

void Boat::debark(const Person& person) {
    currentBank->push_back(person);
    remove(person);
}

std::ostream& operator << (std::ostream& os, const Boat* boat) {
    os << boat->name << ": < ";
    for (const Person &p: boat->people) {
        os << " " << p;
    }
    os << " > ";

    return os;
};