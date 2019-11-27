//
// Created by eengm on 11/12/2019.
//

#include "Insect.h"

/**
 * Default constructor if bee or ant constructor is not used
 */
Insect::Insect() {
    armor = 0;
    name = "Bob the insect";
    position = 0;
}
/**
 * Reduces armor for the insect
 * @param amount
 */
void Insect::reduceArmor(int amount) {
    armor -= amount;
}
/**
 * Getter for armor value
 * @return
 */
int Insect::getArmor() const {
    return armor;
}
/**
 * setter for position value
 * @param position
 */
void Insect::setPosition(int position) {
    this->position = position;
}
/**
 * getter for position value
 * @return
 */
int Insect::getPosition() const {
    return position;
}

