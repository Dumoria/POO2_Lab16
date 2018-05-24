/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 14
File        : cstring.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 22.03.2018
Class       : POO - A

Goal        :

Remark(s)   : Main class of the programm
----------------------------------------------------------------------------------------
*/

#include <string>
#include <iostream>
#include "../headers/Controller/Controller.h"


int main() {

    bool exit = false;
    std::string cmd;

    Model model;
    View view(&model);
    Controller controller(&model, &view);

    while (!exit) {
        std::getline(std::cin, cmd);
        controller.setCmd(cmd);
        exit = controller.command();
    }

    return EXIT_SUCCESS;
}