/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : View.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of the view

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_GOBET_THOMAS_VIEW_H
#define POO2_LABO4_GOBET_THOMAS_VIEW_H

#include <string>
#include <iostream>
#include <utility>
#include "../Controller/Controller.h"
#include "../Model/Bank.h"
#include "../Model/Boat.h"
#include "../Model/Model.h"

const std::string DELIM_LINE = "-----------------------------------------------------------";
const std::string DELIM_LINE_THICK = "===========================================================";
const std::string MENU = "p\t\t: afficher\ne <nom>\t\t: embarquer <nom>\nd <nom>\t\t: debarquer <nom>\n"
"m\t\t: deplacer bateau\nr\t\t: reinitialiser\nq\t\t: quitter\nh\t\t: menu\n";

class View{
    friend class Model;
    Model model;

public:
    explicit View(const Model &model) : model(model) {};

    void initialDisplay() const {
        menuDisplay();
        display();
    }

    void menuDisplay() const {
        std::cout << MENU << std::endl;
    }

    void display() const {
        bankDisplay(model.left);
        riverDisplay();
        bankDisplay(model.right);
    }

    void turnDisplay(short unsigned int turn) const {
        std::cout << std::endl << turn << "> ";
    }

    void bankDisplay(Bank *bank) const {
        std::cout << DELIM_LINE << std::endl;
        std::cout << bank << std::endl;
        std::cout << DELIM_LINE << std::endl;
    }

    void riverDisplay() const {
        boatDisplay(model.left);
        std::cout << DELIM_LINE_THICK << std::endl;
        boatDisplay(model.right);
    }

    void boatDisplay(Bank *bank) const {
        if (model.boat->getCurrentBank() == bank) {
            std::cout << model.boat << std::endl;
        } else {
            std::cout << std::endl;
        }
    }

    void messageDisplay(std::string &msg) const {
        std::cout << "### " << msg << std::endl;
    }

};


#endif //POO2_LABO4_GOBET_THOMAS_VIEW_H
