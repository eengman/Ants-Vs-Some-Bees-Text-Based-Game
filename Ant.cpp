//
// Created by eengm on 11/12/2019.
//

#include "Ant.h"

Ant::Ant() {
    armor = 2;
    foodCost = 1;
    name = "Bob the Ant";
}

void Ant::createAnt(int foodBank) {
    foodBank -= foodCost;
}

Harvester::Harvester() {
    armor = 1;
    foodCost = 1;
    name = "Harvester";

}

void Harvester::action() {
    cout << "Harvester Action" << endl;
}

void Harvester::action(B &b) {

}


Thrower::Thrower() {
    armor = 1;
    foodCost = 4;
    name = "Thrower";
    damage = 1;
}


void Thrower::action() {
    cout << "Thrower action" << endl;
}


