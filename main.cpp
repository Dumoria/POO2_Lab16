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
    View view(model);
    Controller controller(model, view);

    while (!exit) {
        std::getline(std::cin, cmd);
        controller.setCmd(cmd);
        exit = controller.command();
    }

    return EXIT_SUCCESS;
}