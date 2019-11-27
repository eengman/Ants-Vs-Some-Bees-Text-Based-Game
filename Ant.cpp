//
// Created by eengm on 11/12/2019.
//

#include "Ant.h"

/**
 * Ant constructor
 */

Ant::Ant() {
    armor = 2;
    foodCost = 1;
    foodBank = 50;
    name = "Bob the Ant";
}
/**
 * Function that creates each ant and updates the foodbank
 * @param foodBank
 */
void Ant::createAnt(int &foodBank) {
    foodBank -= foodCost;
    cout << name << " created" << ", Colony Food Bank: " << foodBank <<  endl;
}

/**
 * Returns that the object is an ant
 * @return
 */
bool Ant::isAnt() {
    return true;
}

/**
 * Harvester constructor
 * @param position
 * @param foodBank
 */
Harvester::Harvester(int position, int &foodBank) {
    armor = 1;
    foodCost = 1;
    name = "Harvester";
    this->position = position;
    createAnt(foodBank);
}

/**
 * Harvester action, adds one food to colony each turn
 * @param foodBank
 * @param vect
 * @param vect2
 */
void Harvester::action(int &foodBank, vector <Insect*> &vect, vector<Insect*> &vect2) {
    foodBank += 1;
}

/**
 * Thrower constructor
 * @param position
 * @param foodBank
 */
Thrower::Thrower(int position, int &foodBank) {
    armor = 1;
    foodCost = 4;
    name = "Thrower";
    damage = 1;
    this->position = position;
    createAnt(foodBank);
}

/**
 * Thrower action, damages any bee that shares its position
 * @param foodBank
 * @param bees
 * @param ants
 */
void Thrower::action(int &foodBank, vector <Insect*> &bees, vector<Insect*> &ants) {

    for(int i = 0; i < bees.size(); i++){
        if(this->position == bees[i]->getPosition()){
            cout << "Thrower attacks bee at position " << this->position << endl;
            bees[i]->reduceArmor(1);
        }
    }
}

/**
 * Fire ant constructor
 * @param position
 * @param foodBank
 */
Fire::Fire(int position, int &foodBank) {
    armor = 1;
    foodCost = 4;
    name = "Fire";
    this->position = position;
    createAnt(foodBank);
}

/**
 * Fire ant action, kills any bees sharing its square on death
 * @param foodBank
 * @param bees
 * @param ants
 */
void Fire::action(int &foodBank, vector<Insect *> &bees, vector<Insect*> &ants) {
    int numBeesKilled = 0;

    vector<Insect*>:: iterator beeItr;
    for(beeItr = bees.begin(); beeItr != bees.end(); beeItr++){
        Insect* bee = *beeItr;

        if(this->position == bee->position){
            bee->reduceArmor(bee->getArmor());
            bees.erase(beeItr);
            this->armor = 0;
        }
    }

}

/**
 * Long thrower constructor
 * @param position
 * @param foodBank
 */
LongThrower::LongThrower(int position, int &foodBank) {
    armor = 1;
    foodCost = 3;
    name = "Long Thrower";
    minRange = 4;
    this->position = position;
    createAnt(foodBank);
}

/**
 * Long thrower action, damages closest bees at least 4 squares away
 * @param foodBank
 * @param bees
 * @param ants
 */
void LongThrower::action(int &foodBank, vector<Insect *> &bees, vector<Insect*> &ants) {
    int numLoop = 0;
    int closest = 0;
    // find position of the closest bee(s) to relative to own position
    for(int i = 0; i < bees.size(); i++){
        if((bees[i]->position - this->position) >= 4 ){
            closest = bees[i]->position;
            i = bees.size();
        }
    }
    // use position temp variable for comparison
    vector<Insect*>:: iterator itr;
    Insect* bee;
    for(itr = bees.begin(); itr != bees.end(); itr++){
        bee = *itr;
        if(bee->position == closest){
            cout << "Long thrower attacks" << endl;
            bee->reduceArmor(1);
            if(bee->getArmor() <= 0){
                bees.erase(itr);
                cout << "Bee dies by long thrower" << endl;
            }

        }
    }
}

/**
 * Short thrower constructor
 * @param position
 * @param foodBank
 */
ShortThrower::ShortThrower(int position, int &foodBank) {
    armor = 1;
    foodCost = 3;
    name = "Short Thrower";
    minRange = 2;
    this->position = position;
    createAnt(foodBank);

}

/**
 * Short thrower action, damages closest bees at most 2 squares away
 * @param foodBank
 * @param bees
 * @param vect2
 */
void ShortThrower::action(int &foodBank, vector<Insect *> &bees, vector<Insect*> &vect2) {
    int numLoop = 0;
    int closest = 0;
    for(int i = 0; i < bees.size(); i++){
        if((bees[i]->position - this->position) <= 2 ){
            closest = bees[i]->position;
            i = bees.size();
        }
    }
    for(int i = 0; i < bees.size(); i++){
        if(bees[i]->position == closest){
            cout << "Short thrower attacks" << endl;
            bees[i]->reduceArmor(1);
        }
    }
}

/**
 * Wall constructor
 * @param position
 * @param foodBank
 */
Wall::Wall(int position, int &foodBank) {
    armor = 4;
    foodCost = 4;
    name = "Wall";
    this->position = position;
    createAnt(foodBank);
}

/**
 * Wall action, doesnt do anything
 * @param foodBank
 * @param bees
 * @param ants
 */
void Wall::action(int &foodBank, vector<Insect*> &bees, vector<Insect*> &ants ) {

}

/**
 * Ninja constructor
 * @param position
 * @param foodBank
 */
Ninja::Ninja(int position, int &foodBank) {
    armor = 1;
    foodCost = 6;
    name = "Ninja";
    this->position = position;
    createAnt(foodBank);
}

/**
 * Ninja action, hurts any bees that pass by it
 * @param foodBank
 * @param bees
 * @param ants
 */
void Ninja::action(int &foodBank, vector<Insect *> &bees, vector<Insect*> &ants) {
    for(int i = 0; i < bees.size(); i++ ){
        if(this->position == bees[i]->position){
            bees[i]->reduceArmor(1);
        }
    }
}

/**
 * Bodyguard constructor
 * @param position
 * @param foodBank
 */
Bodyguard::Bodyguard(int position, int &foodBank) {
    armor = 2;
    foodCost = 4;
    name = "Bodyguard";
    this->position = position;
    createAnt(foodBank);
}

/**
 * Bodyguard action, does nothing except be a damage sponge
 * @param foodBank
 * @param bees
 * @param ants
 */
void Bodyguard::action(int &foodBank, vector<Insect *> &bees, vector<Insect*> &ants) {

}
