/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Cop.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of a rule

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_GOBET_THOMAS_RULES_H
#define POO2_LABO4_GOBET_THOMAS_RULES_H

#include <string>;
#include <list>;
#include "Container.h"


class Rule {
    std::string command;
    Container container;
    void *(functionPtr)();

};

#endif //POO2_LABO4_GOBET_THOMAS_RULES_H
