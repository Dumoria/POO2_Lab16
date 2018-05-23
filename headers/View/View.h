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
    explicit View(const Model &model);

    void initialDisplay() const;

    void menuDisplay() const;

    void display() const;

    void turnDisplay(short unsigned int turn) const;

    void bankDisplay(Bank *bank) const;

    void riverDisplay() const;

    void boatDisplay(Bank *bank) const;

    void messageDisplay(std::string &msg) const;
};


#endif //POO2_LABO4_GOBET_THOMAS_VIEW_H
