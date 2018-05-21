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