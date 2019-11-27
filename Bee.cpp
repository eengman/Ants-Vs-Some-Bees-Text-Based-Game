//
// Created by eengm on 11/12/2019.
//

#include "Bee.h"

/**
 * Constructor for bee
 */
Bee::Bee() {
    armor = 3;
    position = 8;
    damage = 1;
    name = "Bee";
}
/**
 * Function that determines if the bee will move or if it will sting
 * @param foodBank
 * @param ants
 * @param bees
 */
void Bee::action(int &foodBank, vector <Insect*> &ants, vector<Insect*> &bees) {

    Insect* in;
    int num;
    bool canMove = true;
    for(int i = 0; i < ants.size(); i++){
        if((this->position) == ants[i]->position && ants[i]->name != "Ninja"){
            cout << "Bee can't move" << endl;
            canMove = false;
            num = i;
            break;
        }
    }
    if(canMove){
        move(ants);
    }else if(!canMove){
        sting(*ants[num], bees, ants);
    }
}

/**
 * This function originally had a lot more code but I decided to move it
 * up into the action method
 * @param vect
 */
void Bee::move(vector <Insect*> vect) {
    this->position -= 1;
}

/**
 *Function that stings any bee that shares the same square as the bee
 * @param insect
 * @param bees
 * @param ants
 */
void Bee::sting(Insect &insect, vector <Insect*> &bees, vector <Insect*> &ants) {

    bool isBodyGuard;
    for(int i = 0; i < ants.size(); i++){
        if(ants[i]->name == "Bodyguard"){
            if(ants[i]->position == insect.position){
                cout << ants[i]->name << endl;
                ants[i]->reduceArmor(1);
                isBodyGuard = true;
            }
        }
    }
    if(!isBodyGuard && insect.name != "Ninja"){
        insect.reduceArmor(1);
    }
}

/**
 * Checks to see whether any of the ants are dead, and if so then it removes it
 * @param ants
 */
void Bee::checkRemove(vector<Insect *> &ants) {
    vector<Insect*>:: iterator antItr;
    Insect* ant;
    if(ants.size() <= 0){
        return;
    }
    for(antItr = ants.begin(); antItr != ants.end(); antItr++){
        ant = *antItr;
        if(ant->getArmor() <= 0){
            cout << ant->name << " has died" << endl;
            *ants.erase(antItr);
        }
    }

}
