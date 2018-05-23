/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Controller.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Implementation of the Controller

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include <utility>
#include <algorithm>
#include "../../headers/Controller/Controller.h"

/**
 * Controller constructor.
 *
 * @param   model   the model used by the controller
 * @param   view    the view used by the controller
 */
Controller::Controller(const Model &model, const View &view) : model(model), view(view) {
    view.initialDisplay();
    turnDisplay();

    setCommands();
    setRules();
};

/**
 * Sets the last entered cmd.
 *
 * @param   cmd   the string entered as a command
 */
void Controller::setCmd(const std::string& cmd) {
    this->cmd = cmd;
};

/**
 * Sets the command list.
 *
 * Allows to add quickly a command to the controller.
 *
 * @see     Command
 */
 void Controller::setCommands() {
    commands.emplace_back('p', &Controller::commandP, false);
    commands.emplace_back('e', &Controller::commandE, &Controller::commandEReverse, true);
    commands.emplace_back('d', &Controller::commandD, &Controller::commandDReverse, true);
    commands.emplace_back('m', &Controller::commandM, &Controller::commandMReverse, true);
    commands.emplace_back('r', &Controller::commandR, false);
    commands.emplace_back('h', &Controller::commandH, false);
    commands.emplace_back('q', &Controller::commandQ, false);
}

/** --------------------------- methods used in setCommands -------------------------- **/

/**
 * All methods linked to set up commands.
 */
void Controller::commandP() {
    display();
}
void Controller::commandE() {
    embark(cmd.substr(2));
}
void Controller::commandEReverse() {
    debark(cmd.substr(2));
}
void Controller::commandD() {
    debark(cmd.substr(2));
}
void Controller::commandDReverse() {
    embark(cmd.substr(2));
}
void Controller::commandM() {
    move();
}
void Controller::commandMReverse() {
    move();
}
void Controller::commandR() {
    reinit();
    msg = "Reinitialisation";
    messageDisplay();
    display();
}
void Controller::commandH() {
    showMenu();
}
void Controller::commandQ() {
    quit();
}

/** -------------------------- functions used in setRules ----------------------------- **/

/**
 * Checks if a name is entered after the char command.
 *
 * @param   *container  not used, but needed to comply with the rule function typedef
 * @param   cmd         the cmd string last entered
 * @see     Rule
 */
bool checkName(Container *container, const std::string &cmd) {
    return (cmd.length() <= 2);
}

/**
 * Checks a person is found in  given container.
 *
 * @param   *container  the container to search in
 * @param   cmd         the cmd string last entered containing the searched person
 * @see     Rule
 */
bool findPerson(Container *container, const std::string &cmd) {
    for (auto person : container->getPeople()) {
        if (person == cmd.substr(2))
            return false;
    }
    return true;
}

/**
 * Checks if at least one person in the container can drive.
 *
 * @param   *container  the container to search in
 * @param   cmd         not used, but needed to comply with the rule function typedef
 * @see     Rule
 */
bool canDrive(Container *container, const std::string &cmd) {
    for (const Person *p : container->getPeople()) {
        if (p->canDrive()) {
            return false;
        }
    }
    return true;
}

/**
 * Checks if the thief is present in the container with a family member without the cop.
 *
 * @param   *container  the container to check in
 * @param   cmd         not used, but needed to comply with the rule function typedef
 * @see     Rule
 */
bool thiefMemberNoCop(Container *container, const std::string &cmd) {
    bool thief = false;
    bool member = false;
    bool cop = false;

    for (Person *p : container->getPeople()) {
        if ((dynamic_cast<Thief*>(p)) != nullptr)
            thief = true;

        if ((dynamic_cast<FamilyMember*>(p)) != nullptr)
            member = true;

        if ((dynamic_cast<Cop*>(p)) != nullptr)
            cop = true;
    }
    return (thief && member && !cop);
}

/**
 * Checks if a son is present in the container with is mother and without his father.
 *
 * @param   *container  the container to check in
 * @param   cmd         not used, but needed to comply with the rule function typedef
 * @see     Rule
 */
bool sonMotherNoFather(Container *container, const std::string &cmd) {
    bool son = false;
    bool mother = false;
    bool father = false;

    for (Person *p : container->getPeople()) {
        if ((dynamic_cast<Child*>(p)) != nullptr && p->getGender() == M)
            son = true;

        if ((dynamic_cast<Parent*>(p)) != nullptr && p->getGender() == F)
            mother = true;

        if ((dynamic_cast<Parent*>(p)) != nullptr && p->getGender() == M)
            father = true;
    }
    return (son && mother && !father);
}

/**
 * Checks if a daughter is present in the container with her father and without her mother.
 *
 * @param   *container  the container to check in
 * @param   cmd         not used, but needed to comply with the rule function typedef
 * @see     Rule
 */
bool daughterFatherNoMother(Container *container, const std::string &cmd) {
    bool daughter = false;
    bool father = false;
    bool mother = false;

    for (Person *p : container->getPeople()) {
        if ((dynamic_cast<Child*>(p)) != nullptr && p->getGender() == F)
            daughter = true;

        if ((dynamic_cast<Parent*>(p)) != nullptr && p->getGender() == M)
            father = true;

        if ((dynamic_cast<Parent*>(p)) != nullptr && p->getGender() == F)
            mother = true;
    }
    return (daughter && father && !mother);
}

/**
 * Sets the rule list.
 *
 * Allows to add quickly a rule to the controller.
 * Each rule is composed of: the char corresponding to the command to check,
 * a bool indicating it the rules is tested before (true) or after the command uses its defined method,
 * a bool indicting which container to test (boat = true, currentBank = false),
 * the function to test returning a bool (true = error),
 * the message to display in case of error.
 *
 * @see     Rule
 */
void Controller::setRules() {
    // error messages
    const std::string ERROR_NONAME = "nom de la personne non precisee",
            ERROR_MAX_PEOPLE = "maximum 2 personnes sur le bateau",
            ERROR_NOBODY = "personne de ce nom n'est present",
            ERROR_CANT_DRIVE = "personne ne peut conduire le bateau",
            ERROR_THIEF = "voleur avec membre de famille sans policier",
            ERROR_SON = "garcon avec sa mere sans son pere",
            ERROR_DAUGHTER = "fille avec son pere sans sa mere";

    rules.emplace_back('e', true, true, checkName, ERROR_NONAME);
    rules.emplace_back('d', true, true, checkName, ERROR_NONAME);
    // max people in container boat
    rules.emplace_back('e', true, true, [](Container *container, const std::string &cmd) {
        return (container->getPeople().size() >= container->getMax());
    }, ERROR_MAX_PEOPLE);
    rules.emplace_back('e', true, false, findPerson, ERROR_NOBODY);
    rules.emplace_back('d', true, true, findPerson, ERROR_NOBODY);
    rules.emplace_back('m', true, true, canDrive, ERROR_CANT_DRIVE);

    rules.emplace_back('e', false, true, thiefMemberNoCop, ERROR_THIEF);
    rules.emplace_back('e', false, false, thiefMemberNoCop, ERROR_THIEF);
    rules.emplace_back('d', false, false, thiefMemberNoCop, ERROR_THIEF);

    rules.emplace_back('e', false, true, sonMotherNoFather, ERROR_SON);
    rules.emplace_back('e', false, false, sonMotherNoFather, ERROR_SON);
    rules.emplace_back('d', false, false, sonMotherNoFather, ERROR_SON);

    rules.emplace_back('e', false, true, daughterFatherNoMother, ERROR_DAUGHTER);
    rules.emplace_back('e', false, false, daughterFatherNoMother, ERROR_DAUGHTER);
    rules.emplace_back('d', false, false, daughterFatherNoMother, ERROR_DAUGHTER);
}

/**
 * Called to use the las entered cmd.
 *
 * The command list is browsed to check if the command exists.
 * The rule list is then checked before and after executing the commands
 * in order to see if an error occurred.
 */
const bool Controller::command() {
    bool foundCmd = false;
    error = false;
    std::list<Person*> bankPeople = model.boat->getCurrentBank()->getPeople(),
            boatPeople = model.boat->getPeople();

    // browses the command list
    for (auto command : commands) {
        if (cmd.at(0) == command.cmd && (cmd.length() == 1 || cmd.at(1) == ' ')) {
            checkRules(true);
            if (!error) {
                // if no error, use the main command method
                (this->*command.commandMethod)();
                checkRules(false);

                if (error) {
                    (this->*command.commandReverseMethod)();
                }
            }

            if (command.increaseTurn) {
                if (!error)
                    display();
                nextTurn();
            }

            foundCmd = true;
            break;
        }
    }

    if (!foundCmd) {
        error = true;
        msg = "Commande non valide";
    }

    if (!exit) {
        if (error) {
            messageDisplay();
        }
        turnDisplay();
    } else {
        model.destruct();
    }

    return exit;
}

/**
 * Checks the rule list in order to see if an error occurred.
 *
 * @param   before  boolean indicating if we need the set of rules before or after
 */
void Controller::checkRules(bool before) {
    for (auto rule : rules) {
        if (cmd.at(0) == rule.getCommand() && (rule.getBefore() == before)) {
            Container *container;
            if (rule.getContainer()) {
                container = model.boat;
            } else {
                container = model.boat->getCurrentBank();
            }

            error = rule.checkRule(container, cmd);
            if (error) {
                msg = rule.returnMessage();
                break;
            }
        }
    }
}

/**
 * Displays the command menu.
 */
void Controller::showMenu(){
    view.menuDisplay();
}

/**
 * Displays the current model state.
 */
void Controller::display() {
    view.display();
}

/**
 * Displays a message.
 *
 * @param   msg   the message to display
 */
void Controller::messageDisplay() {
    view.messageDisplay(msg);
}

/**
 * Displays the current turn
 *
 * @param   cmd   the string entered as a command
 */
void Controller::turnDisplay() {
    view.turnDisplay(turn);
}

/**
 * Embarks a person from the bank to the boat.
 *
 * @param   person   the person name to embark
 */
void Controller::embark(const std::string &person) {
    std::list<Person*> bankPeople = model.boat->getCurrentBank()->getPeople();
    auto it = find(bankPeople.begin(), bankPeople.end(), cmd.substr(2));
    model.boat->embark(*it);
}

/**
 * Debarks a person from the boat to the bank.
 *
 * @param   person   the person name to debark
 */
void Controller::debark(const std::string &person) {
    std::list<Person*> boatPeople = model.boat->getPeople();
    auto it = find(boatPeople.begin(), boatPeople.end(), cmd.substr(2));
    model.boat->debark(*it);
}

/**
 * Moves the boat to the other bank.
 */
void Controller::move() {
    model.boat->setCurrentBank(model.boat->getCurrentBank() == model.left ? model.right : model.left);
}

/**
 * Increases the turn number.
 */
void Controller::nextTurn() {
    turn++;
}

/**
 * Reinitialize the model.
 */
void Controller::reinit() {
    turn = 0;
    model.reinit();
}

/**
 * Exits the application.
 */
void Controller::quit() {
    msg = "Au revoir !";
    messageDisplay();
    exit = true;
}
