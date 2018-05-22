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
#include "../../headers/Controller/Controller.h"
#include "../../headers/Model/Rule.h"
#include "../../headers/view/View.h"

Controller::Controller(const Model &model) : model(model), view(View(model)) {
    view.initialDisplay();
    view.turnDisplay(turn);

    setCommands();
};

const bool Controller::command() {
   bool canDrive;
    std::string msg, person;
    std::list<Person*> bankPeople = model.boat->getCurrentBank()->getPeople(),
            boatPeople = model.boat->getPeople();

    // Parcourt la liste des commandes
    for (auto command : commands) {
        if (cmd.at(0) == command.cmd) {
           (this->*command.commandFunction)();
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

    if (!exit) {
        if (!error) {
            view.display();
        } else {
            view.messageDisplay(msg);
        }
    } else {
        delete model.left;
        delete model.right;
        delete model.boat;
    }

    return exit;
}

void Controller::setCmd(const std::string& cmd) {
    this->cmd = cmd;
};

// Set command list
void Controller::setCommands() {
    commands.push_back(Command('p', &Controller::display));
    commands.push_back(Command('e', &Controller::embark));
    commands.push_back(Command('d', &Controller::debark));
    commands.push_back(Command('m', &Controller::move));
    commands.push_back(Command('h', &Controller::showMenu));
    commands.push_back(Command('q', &Controller::quit));

}

void Controller::setRules() {

    const std::string ERROR_NOBODY = "Personne de ce nom n'est présent",
            ERROR_MAX_PEOPLE = "Maximum 2 personnes sur le bateau",
            ERROR_CANT_DRIVE = "Personne ne peut conduire le bateau";

    //bool findPerson(Container c, std::string &person) {
        //return std::find_(c.getPeople().begin(), c.getPeople().end(), person) == l.end();
    //}

    //rules.push_back(Rule('e', model.boat->getCurrentBank(), &findPerson, ERROR_NOBODY));
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
        auto it = find(bankPeople.begin(), bankPeople.end(), person);

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

