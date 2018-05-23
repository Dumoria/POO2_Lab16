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
#include "../Model/Model.h"
#include "../Model/Rule.h"
#include "../View/View.h"

/**
 * Definition of methods used in command structure.
 */
class Controller;
typedef void (Controller::*commandMethodDef)();

/**
 * Command structure.
 * A command consists of the char typed to call the command,
 * a command method called if no error occurred in pre-conditions,
 * a reverse command method, called if an error occurred in post-conditions,
 * a boolean indicating if the turn is increased after using the command.
 *
 * This command structure allows to add a new command quickly if needed.
 */
struct Command {
public:
    /**
     * The char used for the command.
     */
    char cmd;

    /**
     * The method used by the command.
     */
    commandMethodDef commandMethod;

    /**
     * The reverse method used by the command.
     */
    commandMethodDef commandReverseMethod;

    /**
     * The bool deciding it the command increases the turn.
     */
    bool increaseTurn;

    /**
     * Command constructor.
     *
     * @param   cmd             the char used to call the command
     * @param   commandMethod   the main command method
     * @param   increaseTurn    the bool indicating if the command increases turn
     */
    Command(char cmd, commandMethodDef commandMethod, bool increaseTurn) : cmd(cmd), commandMethod(commandMethod), increaseTurn(increaseTurn) {};

    /**
     * Command constructor
     *
     * @param   cmd                     the char used to call the command
     * @param   commandMethod           the main command method
     * @param   commandReverseMethod    the reverse command method
     * @param   increaseTurn            the bool indicating if the command increases turn
     */
    Command(char cmd, commandMethodDef commandMethod, commandMethodDef commandReverseMethod, bool increaseTurn) :
            cmd(cmd), commandMethod(commandMethod), commandReverseMethod(commandReverseMethod), increaseTurn(increaseTurn) {};
};

/**
 * Controller class.
 */
class Controller {
friend class View;
    /**
     * The turn the user is at.
     */
    unsigned short int turn = 0;

    /**
     * Model used by the controller.
     */
    Model model;

    /**
     * View used by the controller.
     */
    const View view;

    /**
     * Command list.
     */
    std::list<Command> commands;

    /**
     * Rule list.
     */
    std::list<Rule> rules;

    /**
     * Last command entered by the user.
     */
    std::string cmd;

    /**
     * Booleans exit and error.
     */
    bool exit = false, error = false;

    /*
     * The message to display.
     */
    std::string msg;

public:
    Controller(const Model &model, const View &view);

    void setCmd(const std::string& cmd);

    void setCommands();
    void commandP();
    void commandE();
    void commandEReverse();
    void commandD();
    void commandDReverse();
    void commandM();
    void commandMReverse();
    void commandR();
    void commandH();
    void commandQ();

    void setRules();

    const bool command();
    void checkRules(bool before);

    void showMenu();
    void display();
    void messageDisplay();
    void turnDisplay();

    void embark(const std::string &person);
    void debark(const std::string &person);
    void move();
    void nextTurn();

    void reinit();
    void quit();
};


#endif //POO2_LABO4_GOBET_THOMAS_CONTROLLER_H
