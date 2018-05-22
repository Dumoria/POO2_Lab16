/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Controller.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Implementation of the controller

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include "../../headers/Controller/Controller.h"
#include "../../headers/Model/Rule.h"
#include "../../headers/view/View.h"

Controller::Controller(const Model &model) : model(model), view(View(model)) {
    view.initialDisplay();
    view.turnDisplay(turn);

    setCommands();
    setRules();
};

const bool Controller::command() {
    error = false;
    std::list<Person*> bankPeople = model.boat->getCurrentBank()->getPeople(),
            boatPeople = model.boat->getPeople();

    // parcourt la liste des commandes
    for (auto command : commands) {
        if (cmd.at(0) == command.cmd) {
            checkRules(cmd, true);
            if (!error) {
                (this->*command.commandFunction)();

                checkRules(cmd, false);

                if (error) {
                    (this->*command.commandReverseFunction)();
                }

                if (command.increaseTurn)
                    nextTurn();
            }
            break;
        }
    }
    /*
    switch (cmd.at(0)) {
        case 'p':

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
            showMenu();
            break;
        default:
            error = true;
            msg = "Commande non valide";
            break;
    }*/

    //std::cout << "msg : " << msg;
    if (!exit) {
        if (error) {
            view.messageDisplay(msg);
        }
    } else {
        delete model.left;
        delete model.right;
        delete model.boat;
    }

    return exit;
}

void Controller::checkRules(std::string cmd, bool before) {
    for (auto rule : rules) {
        if (cmd.at(0) == rule.getCommand() && (rule.getBefore() == before)) {

            error = rule.checkRule(cmd);
            if (error) {
                msg = rule.returnMessage();
                break;
            }
        }
    }
}

void Controller::setCmd(const std::string& cmd) {
    this->cmd = cmd;
};


void Controller::embarks(const std::string &person) {
    std::list<Person*> bankPeople = model.boat->getCurrentBank()->getPeople();
    auto it = find(bankPeople.begin(), bankPeople.end(), cmd.substr(2));
    model.boat->embark(*it);
}

void Controller::debarks(const std::string &person) {
    std::list<Person*> boatPeople = model.boat->getPeople();
    auto it = find(boatPeople.begin(), boatPeople.end(), cmd.substr(2));
    model.boat->debark(*it);
}

void Controller::moves(Boat *boat, Bank *left, Bank *right) {
    boat->setCurrentBank(boat->getCurrentBank() == left ? right : left);
}

void Controller::commandP() {
    view.display();
}
void Controller::commandE() {
    embarks(cmd.substr(2));
    if (!error)
        view.display();
}
void Controller::commandEReverse() {
    debarks(cmd.substr(2));
    view.display();
}
void Controller::commandD() {
    debarks(cmd.substr(2));
    if (!error)
        view.display();
}
void Controller::commandDReverse() {
    embarks(cmd.substr(2));
}
void Controller::commandM() {
    moves(model.boat, model.left, model.right);
    if (!error)
        view.display();
}
void Controller::commandMReverse() {
    moves(model.boat, model.left, model.right);
}
void Controller::commandH() {
    view.menuDisplay();
}
void Controller::commandQ() {
    msg = "Au revoir !";
    view.messageDisplay(msg);
    exit = true;
}
// Set command list
void Controller::setCommands() {
    /*commandFunctionDef commandP = reinterpret_cast<commandFunctionDef>([&](){});
    commandFunctionDef commandE = [&](){embarks(model.boat->getCurrentBank(), model.boat, cmd.substr(2));};
    commandFunctionDef commandEReverse = [&](){debarks(model.boat->getCurrentBank(), model.boat, cmd.substr(2));};
    commandFunctionDef commandD = [&](){debarks(model.boat->getCurrentBank(), model.boat, cmd.substr(2));};
    commandFunctionDef commandDReverse = [&](){embarks(model.boat->getCurrentBank(), model.boat, cmd.substr(2));};
    commandFunctionDef commandM = [&](){moves(model.boat, model.left, model.right);};
    commandFunctionDef commandMReverse = [&](){moves(model.boat, model.left, model.right);};
    commandFunctionDef commandH = [&](){view.menuDisplay();};
    commandFunctionDef commandQ = [&](){
        msg = "Au revoir !";
        view.messageDisplay(msg);
        exit = true;
    };*/

    commands.emplace_back(Command('p', &Controller::commandP, false));
    commands.emplace_back(Command('e', &Controller::commandE, &Controller::commandEReverse, true));
    commands.emplace_back(Command('d', &Controller::commandD, &Controller::commandDReverse, true));
    commands.emplace_back(Command('m', &Controller::commandM, &Controller::commandMReverse, true));
    commands.emplace_back(Command('h', &Controller::commandH, false));
    commands.emplace_back(Command('q', &Controller::commandQ, false));
}

bool checkName(Container *container, const std::string &cmd) {
    return (cmd.length() <= 2);
}

bool findPerson(Container *container, const std::string &cmd) {
    return find(container->getPeople().begin(), container->getPeople().end(), cmd.substr(2)) == container->getPeople().end();
}

void Controller::setRules() {
    const std::string ERROR_NONAME = "nom de la personne non precisee",
            ERROR_MAX_PEOPLE = "maximum 2 personnes sur le bateau",
            ERROR_NOBODY = "personne de ce nom n'est present",
            ERROR_CANT_DRIVE = "personne ne peut conduire le bateau";

    rules.emplace_back('e', true, model.boat, checkName, ERROR_NONAME);
    rules.emplace_back('e', true, model.boat, [](Container *container, const std::string &cmd) {return (container->getPeople().size() >= container->getMax());}, ERROR_MAX_PEOPLE);
    rules.emplace_back('e', true, model.boat->getCurrentBank(), findPerson, ERROR_NOBODY);
    rules.emplace_back('d', true, model.boat, findPerson, ERROR_NOBODY);

}

void Controller::showMenu(){
    view.menuDisplay();
}

void Controller::display() {
    view.display();
}

void Controller::nextTurn() {
    view.turnDisplay(++turn);
}


void Controller::embark() {
    std::string person;
    std::list<Person*> bankPeople = model.boat->getCurrentBank()->getPeople(),
            boatPeople = model.boat->getPeople();

    if (cmd.length() > 2) {
        person = cmd.substr(2);
        auto it = find(bankPeople.begin(), bankPeople.end(), cmd.substr(2));

        if (boatPeople.size() < model.boat->getMax()) {
            if (it == bankPeople.end()) {
                error = true;
                msg = "La personne " + person + " n'existe pas ou n'est pas presente sur la berge";
            } else {
                model.boat->embark(*it);
            }
        } else {
            error = true;
            msg = "plus de place dans le bateau";
        }
    } else {
        error = true;
        msg = "nom de la personne a embarquer non precisee";
    }

    nextTurn();
}

void Controller::debark() {
    std::string person;
    std::list<Person*> bankPeople = model.boat->getCurrentBank()->getPeople(),
            boatPeople = model.boat->getPeople();

    // factoriser
    if (cmd.length() > 2) {
        person = cmd.substr(2);
        auto it = find(boatPeople.begin(), boatPeople.end(), person);

        if (it == boatPeople.end()) {
            error = true;
            msg = "La personne " + person + " n'existe pas ou n'est pas presente dans le bateau";
        } else {
            model.boat->debark(*it);
        }
    } else {
        error = true;
        msg = "nom de la personne a debarquer non precisee";
    }

    nextTurn();
}

void Controller::move() {
    bool canDrive = false;
    std::list<Person*> boatPeople = model.boat->getPeople();

    for (const Person *p : boatPeople) {
        if (p->canDrive()) {
            canDrive = true;
            break;
        }
    }

    if (canDrive) {
        model.boat->setCurrentBank(model.boat->getCurrentBank() == model.left ? model.right : model.left);
    } else {
        error = true;
        msg = "personne ne peut conduire le bateau";
    }

    nextTurn();
}

void Controller::quit() {
    msg = "Au revoir !";
    view.messageDisplay(msg);
    exit = true;
}

