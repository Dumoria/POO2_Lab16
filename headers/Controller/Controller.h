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

class Controller;
typedef void (Controller::*commandFunctionDef)();

struct Command {
    friend class Controller;
public:
    char cmd;
    commandFunctionDef commandFunction;
    commandFunctionDef commandReverseFunction;
    bool increaseTurn;

    Command(char cmd, commandFunctionDef commandFunction, bool increaseTurn) : cmd(cmd), commandFunction(commandFunction), increaseTurn(increaseTurn) {};
    Command(char cmd, commandFunctionDef commandFunction, commandFunctionDef commandReverseFunction, bool increaseTurn) :
            cmd(cmd), commandFunction(commandFunction), commandReverseFunction(commandReverseFunction), increaseTurn(increaseTurn) {};
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
    std::list<Command> commands;

    // rule list
    std::list<Rule> rules;

    // cmd
    std::string cmd;
    bool exit = false, error = false;
    std::string msg;

public:
    explicit Controller(const Model &model);

    const bool command();

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

    void setCmd(const std::string& cmd);
    void setRules();

    void embarks(const std::string &person);
    void debarks(const std::string &person);
    void moves(Boat *boat, Bank *left, Bank *right);
    void commandP();
    void commandE();
    void commandEReverse();
    void commandD();
    void commandDReverse();
    void commandM();
    void commandMReverse();
    void commandH();
    void commandQ();
    void setCommands();

    void checkRules(std::string cmd, bool before);

    void showMenu();

    void display();

    void nextTurn();

    void embark();
    void debark();
    void move();

    void reinit(){
        //left.reinit();
        //right.reinit();
        //boat.reinit();
    }

    void quit();


};

#endif //POO2_LABO4_GOBET_THOMAS_CONTROLLER_H
