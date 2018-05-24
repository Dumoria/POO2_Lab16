/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : View.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of the View

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_GOBET_THOMAS_VIEW_H
#define POO2_LABO4_GOBET_THOMAS_VIEW_H

#include <string>
#include <iostream>
#include <utility>
#include "../Model/Bank.h"
#include "../Model/Boat.h"
#include "../Model/Model.h"

const std::string DELIM_LINE = "-----------------------------------------------------------";
const std::string DELIM_LINE_THICK = "===========================================================";
const std::string MENU = "p\t\t: afficher\ne <nom>\t\t: embarquer <nom>\nd <nom>\t\t: debarquer <nom>\n"
"m\t\t: deplacer bateau\nr\t\t: reinitialiser\nq\t\t: quitter\nh\t\t: menu\n";

class View {
    friend class Model;
    Model* model;                   //Model to display

public:
    explicit View(Model* model);

    /**
     * Initialize the displayer
     */
    void initialDisplay() const;

    /**
     * Display the menu
     */
    void menuDisplay() const;

    /**
     * Display the river and the banks
     */
    void display() const;

    /**
     * Display the turn
     * @param turn the turn to display
     */
    void turnDisplay(short unsigned int turn) const;

    /**
     * Display a bank
     * @param bank the bank to display
     */
    void bankDisplay(Bank *bank) const;

    /**
     * Display the river
     */
    void riverDisplay() const;

    /**
     * Display the boat
     * @param bank the bank on which the boat is docked
     */
    void boatDisplay(Bank *bank) const;

    /**
     * Display a message
     * @param msg the message to display
     */
    void messageDisplay(std::string &msg) const;
};


#endif //POO2_LABO4_GOBET_THOMAS_VIEW_H
