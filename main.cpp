/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 14
File        : cstring.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 22.03.2018
Class       : POO - A

Goal        :

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include <string>
#include <iostream>
#include "headers/Controller/Controller.h"
#include "headers/model/Parent.h"
#include "headers/Model/Child.h"
#include "headers/Model/Cop.h"
#include "headers/Model/Thief.h"

int main() {
    bool exit = false;
    std::string cmd;

    Model model;
    Controller controller(model);

    while (!exit) {
        std::getline(std::cin, cmd);
        controller.command(cmd);
        exit = false;
    }

    return EXIT_SUCCESS;
}