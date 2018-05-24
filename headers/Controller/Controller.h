/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Controller.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of the Controller

Remark(s)   : -
----------------------------------------------------------------------------------------
*/
#ifndef POO2_LABO4_GOBET_THOMAS_CONTROLLER_H
#define POO2_LABO4_GOBET_THOMAS_CONTROLLER_H

#include <list>
#include "../Model/Bank.h"
#include "../Model/Boat.h"
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

    char cmd;                                       //The char used for the command.
    commandMethodDef commandMethod;                 //The method used by the command.
    commandMethodDef commandReverseMethod;          //The reverse method used by the command.
    bool increaseTurn;                              //The bool deciding it the command increases the turn.

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

    unsigned short int turn = 0;        //The turn the user is at.
    Model* model;                       //Model used by the controller.
    View* view;                         //View used by the controller.
    std::list<Command> commands;        //Command list.
    std::list<Rule> rules;              //Rule list.
    std::string cmd;                    //Last command entered by the user.
    bool exit = false, error = false;   //Booleans exit and error.
    std::string msg;                    //The message to display.

public:

    /**
     * Controller constructor.
     * @param model the model used by the controller
     * @param view the view used by the controller
     */
    Controller(Model* model, View* view);

    /**
     * Sets the last entered cmd.
     * @param cmd the string entered as a command
     */
    void setCmd(const std::string& cmd);

    /**
     * Sets the command list.
     * Allows to add quickly a command to the controller.
     * @see     Command
     */
    void setCommands();

    /** --------------------------- methods used in setCommands -------------------------- **/

    /**
     * All methods linked to set up commands.
     */

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

/** -------------------------------------- **/
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
