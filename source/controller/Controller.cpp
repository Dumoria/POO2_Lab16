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

#include <utility>
#include <algorithm>
#include "../../headers/Controller/Controller.h"
#include "../../headers/Model/Rule.h"
#include "../../headers/view/View.h"

Controller::Controller(const Model &model) : model(model), view(View(model)) {
    view.initialDisplay();
    view.turnDisplay(turn);
};

const bool Controller::command(const std::string &cmd) {
    bool exit = false, error = false;
    std::string msg, person;
    std::list<Person> bankPeople = model.boat->getCurrentBank()->getPeople(),
            boatPeople = model.boat->getPeople();

    switch (cmd.at(0)) {
        case 'p':

            break;
        case 'e':
            if (cmd.length() > 2) {
                person = cmd.substr(2);
                std::cout << person;
                auto it = find(bankPeople.begin(), bankPeople.end(), person);

                if (it == bankPeople.end()) {
                    error = true;
                    msg = "La personne " + person + " n'existe pas ou n'est pas presente sur la berge";
                } else {
                    model.boat->embark(*it);
                }
            } else {
                error = true;
                msg = "nom de la personne a embarquer non precisee";
            }
            break;
        case 'd':
            // factoriser
            if (cmd.length() > 2) {
                person = cmd.substr(2);
                std::cout << person;
                auto it = find(boatPeople.begin(), boatPeople.end(), person);

                if (it == boatPeople.end()) {
                    error = true;
                    msg = "La personne " + person + " n'existe pas ou n'est pas presente dans le bateau";
                } else {
                    model.boat->debark(*it);
                }
            } else {
                error = true;
                msg = "nom de la personne a embarquer non precisee";
            }
            break;
        case 'm':

            break;
        case 'r':

            break;
        case 'q':
            msg = "Au revoir !";
            view.messageDisplay(msg);
            exit = true;
            break;
        case 'h':
            showMenu();
            break;
        default:
            error = true;
            msg = "Commande non valide";
            break;
    }

    if (!exit) {
        if (!error) {
            view.display();
        } else {
            view.messageDisplay(msg);
        }
        nextTurn();
    } else {
        delete model.left;
        delete model.right;
        delete model.boat;
    }

    return exit;
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

void Controller::showMenu() const{
    view.menuDisplay();
}

void Controller::display() const {
    view.display();
}

void Controller::nextTurn() {
    view.turnDisplay(++turn);
}


