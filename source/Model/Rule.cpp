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

Rule::Rule(const char &command, bool before, Container *container, ruleFunctionDef ruleFunction, const std::string &errorMessage) :
        command(command), before(before), container(container), ruleFunction(ruleFunction), errorMessage(errorMessage) {}

bool Rule::checkRule(const std::string &cmd) {
    return ruleFunction(container, cmd);
}

char Rule::getCommand() {
    return command;
}

bool Rule::getBefore() {
    return before;
}

std::string Rule::returnMessage() {
    return errorMessage;
}