/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Controller.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Implementation of the rule

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include "../../headers/Model/Rule.h"

Rule::Rule(const char &command, Container *container, ruleFunctionDef ruleFunction, const std::string &errorMessage) :
        command(command), container(container), ruleFunction(ruleFunction), errorMessage(errorMessage) {}

bool Rule::checkRule() {
    return ruleFunction(*container);
}

char Rule::getCommand() {
    return command;
}

std::string Rule::returnMessage() {
    return errorMessage;
}