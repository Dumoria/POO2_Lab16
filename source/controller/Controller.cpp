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
#include "../../headers/Controller/Controller.h"
#include "../../headers/view/View.h"

Controller::Controller(Model model) : model(model), view(View(model)) {
    view.initialDisplay();
};