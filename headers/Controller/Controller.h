/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Controller.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of the controller

Remark(s)   : -
----------------------------------------------------------------------------------------
*/
#ifndef POO2_LABO4_GOBET_THOMAS_CONTROLLER_H
#define POO2_LABO4_GOBET_THOMAS_CONTROLLER_H

#include <list>
#include "../Model/Boat.h"
#include "../Model/Bank.h"
#include "../View/View.h"
#include "../Model/Model.h"
#include "../Model/Rule.h"

struct Commande {

};

class Controller {
friend class View;
private:
    unsigned short int turn = 0;

    //Model, check si meilleur temps utiliser model ou directe class du mod ici
    const Model model;

    //View
    const View view;

    // command list
    std::list<Commande> commands;

    // rule list
    std::list<Rule> rules;

public:
    explicit Controller(const Model &model);

    const bool command(const std::string &cmd);

    Controller controller() {

        showMenu();
        display();

        char cmd; //cin, vérifier que bien...

        switch(cmd){
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
                break;
            case 'h':
                break;
            default:
                std::cout << "Entrée non valide" << std::endl;
                break;
        }
    }

    void setRules();

    void showMenu() const;

    void display() const;

    void nextTurn();

    void reinit(){
        //left.reinit();
        //right.reinit();
        //boat.reinit();
    }

    void quit();


};

#endif //POO2_LABO4_GOBET_THOMAS_CONTROLLER_H
