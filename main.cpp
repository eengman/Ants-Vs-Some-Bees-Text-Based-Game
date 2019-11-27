#include <iostream>
#include <vector>
#include <string>
#include "Insect.h"
#include "Bee.h"
#include "Ant.h"

/**
 * Program: Ants vs Some Bees Lab 5
 * Author: Eric Engman
 * ID: 40855107
 * Honor code: I pledge this is my work and I received help from no one
 */

using namespace std;

/**
 * Prints the gameboard each turn
 * @param antV vector of ants
 * @param beeV vector of bees
 */
void printBoard(vector <Insect*> antV, vector <Insect*> beeV){
    int position = 1;
    cout << "\nBoard:  " << endl;
    cout << "0: Ant Queen" << endl;
    while(position < 9){
        cout << position << ": ";
        for(int i = 0; i < antV.size(); i++){
            if(antV[i]->position == position && antV[i]->getArmor() != 0){
                cout << antV[i]->name << ", Armor: " << antV[i]->armor << " ";
            }
        }
        for(int i = 0; i < beeV.size(); i++){
            if(beeV[i]->position == position && beeV[i]->getArmor() != 0){
                cout << beeV[i]->name << ", Armor: " << beeV[i]->armor << " ";
            }
        }
        cout << endl;
        position++;
    }
    cout << "9: Bee Hive" << endl;
    cout << endl;
}

/**
 * Checks whether ants are still alive and removes them if they are not, also
 * updates the antCounter array
 * @param ants
 * @param antCounter
 */
void checkAnt(vector <Insect*> &ants, bool antCounter[] ){

    Insect* ant;
    vector <Insect*>:: iterator antItr;
    // ants action each turn
    for(antItr = ants.begin(); antItr != ants.end(); antItr++){
        ant = *antItr;
        if(ant->getArmor() <= 0){
            cout << ant->name << " has died" << endl;
            antCounter[ant->position] = false;
            ants.erase(antItr);
            return;
        }
    }
}
/**
 * Checks to see whether a bee is alive, if it is dead it removes it from the vector that
 * is passed
 * @param bees
 */

void checkBee(vector <Insect*> &bees){

    vector <Insect*>:: iterator beeItr;
    Insect* bee;
    // check all bees current state
    for(beeItr = bees.begin(); beeItr != bees.end(); beeItr++){
        bee = *beeItr;
        if(bee->getArmor() <= 0){
            cout << "Bee at position " << bee->getPosition() << " has died" << endl;
            bees.erase(beeItr);
            if(bees.size() == 0){
                cout << "No more bees left!! You win!!" << endl;
                break;
            }
        }
    }
}

int main() {

    int difficulty;

    cout << "Hello, and welcome to Ants vs Some Bees" << endl;
    cout << "I thought this game could be won to easily so I added some difficulty options" << endl;
    cout << "What option would you like to try?" << endl;
    cout << "1: Easy, starting foodbank of 50" << endl;
    cout << "2: Medium, starting foodbank of 35" << endl;
    cout << "3: Hard, starting foodbank of 25" << endl;
    cin >> difficulty;
    int foodBank;
    switch(difficulty){
        case 1: foodBank = 50;
        break;
        case 2: foodBank = 35;
        break;
        case 3: foodBank = 25;
        break;
    }

    // Keeps track whether there is an ant placed at a certain position
    bool antCounter[10];
    for(int i = 0; i < 10; i++){
        antCounter[i] = false;
    }

    // gameboards for ants and bees
    vector <Insect*> ants;
    vector <Insect*> bees;

    // Insect pointer to ant object
    Insect* ant;
    Insect* bee;

    // Iterators for the vectors
    vector <Insect*>:: iterator beeItr;
    vector <Insect*>:: iterator antItr;

    bool play = true;

    while(play){

        // create new Bee
        bee = new Bee;
        bees.push_back(bee);

        int buffer;
        int choice;
        int position;
        bool occupied = false;
        cout << "\nFood bank: " << foodBank << endl;
        cout << "Number of Bees on board: " << bees.size() << endl;

        while(!occupied){
            printBoard(ants, bees);
            cout << "\nFood bank: " << foodBank << endl;
            cout << "What would you like to do? " << endl;
            cout << "1: Place Harvester, 2: Place Thrower, 3: Place Fire, 4: Place LongThrower " << endl;
            cout << "5: Place ShortThrower, 6: Place Wall, 7: Place Ninja, 8: Place Bodyguard " << endl;
            cin >> choice;
            cout << "Where would you like to place the Ant? " << endl;
            cout << "Enter number 1-8" << endl;
            cin >> position;
            if(!antCounter[position]){
                occupied = true;
            }else if(choice == 8){
                occupied = true;
            }else{
                occupied = false;
                cout << "Sorry, there is already an Ant there!!!" << endl;
                cout << endl;
                system("pause");
            }
        }

        switch(choice){
            case 1:
                ant = new Harvester(position, foodBank);
                ants.push_back(ant);
                antCounter[position] = true;
                break;
            case 2:
                ant = new Thrower(position, foodBank);
                ants.push_back(ant);
                antCounter[position] = true;
                break;
            case 3:
                ant = new Fire(position, foodBank);
                ants.push_back(ant);
                antCounter[position] = true;
                break;
            case 4:
                ant = new LongThrower(position, foodBank);
                ants.push_back(ant);
                antCounter[position] = true;
                break;
            case 5:
                ant = new ShortThrower(position, foodBank);
                ants.push_back(ant);
                antCounter[position] = true;
                break;
            case 6:
                ant = new Wall(position, foodBank);
                ants.push_back(ant);
                antCounter[position] = true;
                break;
            case 7:
                ant = new Ninja(position, foodBank);
                ants.push_back(ant);
                antCounter[position] = true;
                break;
            case 8:
                ant = new Bodyguard(position, foodBank);
                ants.push_back(ant);
                antCounter[position] = false;
                break;
            case 9:
                break;
        }

        // perform ants action
        for(int i = 0; i < ants.size(); i++){
            ants[i]->action(foodBank, bees, ants);
            checkBee(bees);
        }
        // perform bees action
        for(int i = 0; i < bees.size(); i++){
            bees[i]->action(foodBank, ants, bees);
            checkAnt(ants, antCounter);
        }

        // check if there are no more bees left
        if(bees.size() <= 0){
            play = false;
        }

        if(bees.size() > 0){
            for(int i = 0; i < bees.size(); i++){
                if(bees[i]->position == 0){
                    cout << "\nThe Bees have reached the Ant Queen!!!" << endl;
                    cout << "HOW COULD YOU LET HER DIE, YOU SUCK!!!" << endl;
                    cout << "\nGAME OVER" << endl;
                    play = false;
                }
            }
        }

    }

    return 0;
}