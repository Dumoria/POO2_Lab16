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

Rule::Rule(const char &command, bool before, bool container, ruleFunctionDef ruleFunction, const std::string &errorMessage) :
        command(command), before(before), container(container), ruleFunction(ruleFunction), errorMessage(errorMessage) {}

/**
 * Check wether or not the rule is respected
 * @param container the container to check
 * @param cmd the command that results in the rule verification
 * @return a bool to indicate if the rule is respected or not
 */
bool Rule::checkRule(Container *container, const std::string &cmd) {
    return ruleFunction(container, cmd);
}

char Rule::getCommand() {
    return command;
}

bool Rule::getBefore() {
    return before;
}

bool Rule::getContainer() {
    return container;
}

std::string Rule::returnMessage() {
    return errorMessage;
}