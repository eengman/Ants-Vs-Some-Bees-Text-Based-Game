//
// Created by eengm on 11/12/2019.
//

#include "Insect.h"

Insect::Insect() {
    armor = 0;
    name = "Bob the insect";
    position = 0;
}

void Insect::reduceArmor(int amount) {
    armor -= amount;
}

int Insect::getArmor() const {
    return armor;
}

void Insect::setPosition(int position) {
    this->position = position;
}

int Insect::getPosition() const {
    return position;
}


