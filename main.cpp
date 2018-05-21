/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 14
File        : cstring.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 22.03.2018
Class       : POO - A

Goal        :

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include <string>
#include "headers/controller/Controller.h"
#include "headers/model/Parent.h"
#include "headers/Model/Child.h"
#include "headers/Model/Cop.h"
#include "headers/Model/Thief.h"

int main() {
    Parent pere("pere", M), mere("mere", F);
    Child paul("paul", M), pierre("pierre", M), julie("julie", F), jeanne("jeanne", F);
    Cop policier("policier");
    Thief voleur("voleur");
    Bank left("Left", {pere, mere, paul, pierre, julie, jeanne, policier, voleur}), right("Right");
    Boat boat("Bateau", left);

    Controller controller(left, right, boat);

    return EXIT_SUCCESS;
}