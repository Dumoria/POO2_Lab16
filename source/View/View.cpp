/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Controller.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 23.05.2018
Class       : POO - A

Goal        : Implementation of the View

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include "../../headers/View/View.h"

View::View(const Model &model) : model(model) {};

void View::initialDisplay() const {
    menuDisplay();
    display();
}

void View::menuDisplay() const {
    std::cout << MENU << std::endl;
}

void View::display() const {
    bankDisplay(model.left);
    riverDisplay();
    bankDisplay(model.right);
}

void View::turnDisplay(short unsigned int turn) const {
    std::cout << std::endl << turn << "> ";
}

void View::bankDisplay(Bank *bank) const {
    std::cout << DELIM_LINE << std::endl;
    std::cout << bank << std::endl;
    std::cout << DELIM_LINE << std::endl;
}

void View::riverDisplay() const {
    boatDisplay(model.left);
    std::cout << DELIM_LINE_THICK << std::endl;
    boatDisplay(model.right);
}

void View::boatDisplay(Bank *bank) const {
    if (model.boat->getCurrentBank() == bank) {
        std::cout << model.boat << std::endl;
    } else {
        std::cout << std::endl;
    }
}

void View::messageDisplay(std::string &msg) const {
    std::cout << "### " << msg << std::endl;
}
