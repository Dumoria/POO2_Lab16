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
    bool foundCmd = false;
    error = false;
    std::list<Person*> bankPeople = model.boat->getCurrentBank()->getPeople(),
            boatPeople = model.boat->getPeople();

    // parcourt la liste des commandes
    for (auto command : commands) {
        if (cmd.at(0) == command.cmd && (cmd.length() == 1 || cmd.at(1) == ' ')) {
            checkRules(cmd, true);
            if (!error) {
                (this->*command.commandFunction)();
                checkRules(cmd, false);

                if (error) {
                    (this->*command.commandReverseFunction)();
                }
            }

            if (command.increaseTurn) {
                if (!error)
                    view.display();
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
        view.turnDisplay(turn);
    } else {
        model.destruct();
    }

    return exit;
}

void Controller::checkRules(std::string cmd, bool before) {
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
}
void Controller::commandEReverse() {
    debarks(cmd.substr(2));
}
void Controller::commandD() {
    debarks(cmd.substr(2));
}
void Controller::commandDReverse() {
    embarks(cmd.substr(2));
}
void Controller::commandM() {
    moves(model.boat, model.left, model.right);
}
void Controller::commandMReverse() {
    moves(model.boat, model.left, model.right);
}
void Controller::commandR() {
    turn = 0;
    model.reinit();
    msg = "Reinitialisation";
    view.messageDisplay(msg);
    view.display();
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
    commands.emplace_back('p', &Controller::commandP, false);
    commands.emplace_back('e', &Controller::commandE, &Controller::commandEReverse, true);
    commands.emplace_back('d', &Controller::commandD, &Controller::commandDReverse, true);
    commands.emplace_back('m', &Controller::commandM, &Controller::commandMReverse, true);
    commands.emplace_back('r', &Controller::commandR, false);
    commands.emplace_back('h', &Controller::commandH, false);
    commands.emplace_back('q', &Controller::commandQ, false);
}

bool checkName(Container *container, const std::string &cmd) {
    return (cmd.length() <= 2);
}

bool findPerson(Container *container, const std::string &cmd) {
    for (auto person : container->getPeople()) {
        if (person == cmd.substr(2))
            return false;
    }

    return true;
    //auto it = find(container->getPeople().begin(), container->getPeople().end(), cmd.substr(2));
    //return (it == container->getPeople().end());
}

bool canDrive(Container *container, const std::string &cmd) {
    for (const Person *p : container->getPeople()) {
        if (p->canDrive()) {
            return false;
        }
    }
    return true;
}

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

void Controller::setRules() {
    const std::string ERROR_NONAME = "nom de la personne non precisee",
            ERROR_MAX_PEOPLE = "maximum 2 personnes sur le bateau",
            ERROR_NOBODY = "personne de ce nom n'est present",
            ERROR_CANT_DRIVE = "personne ne peut conduire le bateau",
            ERROR_THIEF = "voleur avec membre de famille sans policier",
            ERROR_SON = "garcon avec sa mere sans son pere",
            ERROR_DAUGHTER = "fille avec son pere sans sa mere";

    rules.emplace_back('e', true, true, checkName, ERROR_NONAME);
    rules.emplace_back('d', true, true, checkName, ERROR_NONAME);
    rules.emplace_back('e', true, true, [](Container *container, const std::string &cmd) {return (container->getPeople().size() >= container->getMax());}, ERROR_MAX_PEOPLE);
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

void Controller::showMenu(){
    view.menuDisplay();
}

void Controller::display() {
    view.display();
}

void Controller::nextTurn() {
    turn++;
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

