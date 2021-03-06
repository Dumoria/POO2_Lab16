/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Personn.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 23.05.2018
Class       : POO - A

Goal        : Declaration of a personn

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef POO2_LAB16_MODEL_H
#define POO2_LAB16_MODEL_H

#include <memory>
#include "Bank.h"
#include "Boat.h"
#include "Parent.h"
#include "Child.h"
#include "Cop.h"
#include "Thief.h"

class Model{
    friend class View;
    friend class Controller;

    Bank* left;         //The left bank
    Bank* right;        //The right bank
    Boat* boat;         //The boat

    //All the people present
    Parent *pere, *mere;
    Child *paul, *pierre, *julie, *jeanne;
    Cop *policier;
    Thief *voleur;

public:
    Model() : left(new Bank("Left")), right(new Bank("right")), boat(new Boat("Boat", left)) {
        populate();
        left->push_back({pere, mere, paul, pierre, julie, jeanne, policier, voleur});
    };

    ~Model() {
        delete pere;
        delete mere;
        delete paul;
        delete pierre;
        delete julie;
        delete jeanne;
        delete policier;
        delete voleur;

        delete left;
        delete right;
        delete boat;
    }

    /**
     * Populate the model with new data
     */
    void populate() {
        pere = new Parent("pere", M);
        mere = new Parent("mere", F);
        paul = new Child("paul", M);
        pierre = new Child("pierre", M);
        julie = new Child("julie", F);
        jeanne = new Child("jeanne", F);
        policier = new Cop("policier", M);
        voleur = new Thief("voleur", M);
    };

    Bank* getRightBank(){
        return right;
    }

    Bank* getLeftBank(){
        return left;
    }

    Boat* getBoat(){
        return boat;
    }

    /**
     * Reinitialize the model
     */
    void reinit() {
        left->clear();
        right->clear();
        boat->clear();
        boat->setCurrentBank(left);
        populate();
        left->push_back({pere, mere, paul, pierre, julie, jeanne, policier, voleur});
    }

};

#endif //POO2_LAB16_MODEL_H
