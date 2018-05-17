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
#include "../Model/Bank.h"
#include "../Model/Boat.h"

const std::string DELIM_LINE = "-----------------------------------------------------------";
const std::string DELIM_LINE_THICK = "===========================================================";
const std::string MENU = "p\t: afficher\ne <nom>\t: embarquer <nom>\nd <nom>\t: debarquer <nom>\n"
"m\t: deplacer bateau\nr\t: reinitialiser\nq\t: quitter\nh\t: menu\n";

class View{

private:

public:

    View view();

    void initialDisplay(){
        menuDisplay();
        std::cout << DELIM_LINE << std:: endl;

    }

    void menuDisplay(){
        std::cout << MENU << std::endl;
    }

    void bankDisplay(Bank bank){
        /*Pour chaque personne de la bank
         *  p.getName();
         *
         */
    }

    void boatDisplay(Boat boat){

    }

};


#endif //POO2_LABO4_GOBET_THOMAS_VIEW_H
