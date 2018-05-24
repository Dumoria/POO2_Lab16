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
    char command;                   //Char that drive the rule check
    bool before;                    //Indicate if the rule need to be tested before or after the command's application
    bool container;                 //Indicate if the rule is linked to the boat or the banks
    ruleFunctionDef ruleFunction;   //The function to test to know if the rule is respected or not
    std::string errorMessage;       //The message to print if there is an error

public:
    Rule(const char &command, bool before, bool container, ruleFunctionDef ruleFunction, const std::string &errorMessage);

    /**
     * Check wether or not the rule is respected
     * @param container the container to check
     * @param cmd the command that results in the rule verification
     * @return a bool to indicate if the rule is respected or not
     */
    bool checkRule(Container *container, const std::string &cmd);

    char getCommand();
    bool getBefore();
    bool getContainer();
    std::string returnMessage();
};

#endif //POO2_LABO4_GOBET_THOMAS_RULES_H
