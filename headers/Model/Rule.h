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

#include <string>
#include <list>
#include "Container.h"

typedef bool (*ruleFunctionDef)(Container *container, const std::string &s);

class Rule {
    char command;
    bool before;
    Container *container;
    ruleFunctionDef ruleFunction;
    std::string errorMessage;

public:
    Rule(const char &command, bool before, Container *container, ruleFunctionDef ruleFunction, const std::string &errorMessage);

    bool checkRule(const std::string &cmd);
    char getCommand();
    bool getBefore();
    std::string returnMessage();
};

#endif //POO2_LABO4_GOBET_THOMAS_RULES_H
