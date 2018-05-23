//
// Created by benja on 17.05.2018.
//

#ifndef POO2_LAB16_MODEL_H
#define POO2_LAB16_MODEL_H

#include <memory>
#include "Parent.h"
#include "Child.h"
#include "Cop.h"
#include "Thief.h"

class Model{
    friend class View;
    friend class Controller;

    Bank* left;
    Bank* right;
    Boat* boat;

    Parent *pere = new Parent("pere", M), *mere = new Parent("mere", F);
    Child *paul = new Child("paul", M), *pierre = new Child("pierre", M),
            *julie = new Child("julie", F), *jeanne = new Child("jeanne", F);
    Cop *policier = new Cop("policier", M);
    Thief *voleur = new Thief("voleur", M);

    std::initializer_list<Person*> initList;

public:

    Model() : left(new Bank("Left")), right(new Bank("right")), boat(new Boat("Boat", left)) {
        initList = {pere, mere, paul, pierre, julie, jeanne, policier, voleur};
        left->push_back(initList);
    };

    ~Model() {
        destruct();
    }

    void destruct() {
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

    Bank* getRightBank(){
        return right;
    }

    Bank* getLeftBank(){
        return left;
    }

    Boat* getBoat(){
        return boat;
    }

    void reinit() {
        left->getPeople().clear();
        right->getPeople().clear();
        boat->getPeople().clear();
        boat->setCurrentBank(left);
        //left->push_back(initList);
    }

    //void setRightBank(Bank bank){
    //    right = bank;
    //}
//
    //void setLeftBank(Bank bank){
    //    left = bank;
    //}
//
    //void setBoat(Boat boat){
    //    this->boat = boat;
    //}

};

#endif //POO2_LAB16_MODEL_H
