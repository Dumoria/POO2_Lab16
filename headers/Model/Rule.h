//
// Created by benja on 03.05.2018.
//

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
