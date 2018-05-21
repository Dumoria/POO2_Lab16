/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Controller.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Implementation of the controller

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include <utility>
#include "../../headers/Controller/Controller.h"
#include "../../headers/view/View.h"

Controller::Controller(Model model) : model(model), view(View(model)) {
    view.initialDisplay();
};

bool Controller::command(const std::string &cmd) const {
    bool exit = false, error = false;
    std::string msg;

    switch (cmd.at(0)) {
        case 'p':
            view.display();
            break;
        case 'e':

            break;
        case 'd':

            break;
        case 'm':

            break;
        case 'r':

            break;
        case 'q':
            msg = "Au revoir !";
            exit = true;
            break;
        case 'h':
            view.menuDisplay();
            break;
        default:
            error = true;
            msg = "Commande non valide";
            break;
    }

    if (!error && !exit) {
        view.display();
    } else {
        view.messageDisplay(msg);
    }

    return exit;
}