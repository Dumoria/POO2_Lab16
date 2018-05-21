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

#include "../Model/Boat.h"
#include "../Model/Bank.h"
#include "../View/View.h"
#include "../Model/Model.h"

class Controller {
friend class View;
private:
    int turn = 0;

    //Model, check si meilleur temps utiliser model ou directe class du mod ici
    Model model;

    //View
    View view;

public:
    explicit Controller(Model model);

    Controller controller() {

        showMenu();
        display();

        char cmd; //cin, vérifier que bien...

        switch(cmd){
            case 'p':
                display();
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

    void showMenu(){
        view.menuDisplay();
    }

    void display();

    void nextTurn();

    void reinit(){
        //left.reinit();
        //right.reinit();
        //boat.reinit();
    }

    void quit();


};

#endif //POO2_LABO4_GOBET_THOMAS_CONTROLLER_H
