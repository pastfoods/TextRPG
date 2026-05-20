#include "Rogue.h"
#include <string>
#include <iostream>
using namespace std;
Rogue::Rogue(std::string name, int maxHp, int maxMp, int power, int defence) : Player(name, maxHp, maxMp, power, defence)
{
    this->power += 30;
    setJob("Rogue");

}


void Rogue::attack(Monster* monster) {
    int damage = (power - monster->getDefence()) / 5;
    int monsterBeforeHp = monster->getHp();
    if (damage <= 0)
    {
        damage = 1;
    }
    cout << "[Rogue] Stabs dagger! -> " << damage << " damage to " << monster->getName() << "! (X5)" << endl;
    monster->setHp(monster->getHp() - (damage * 5));
    cout << monster->getName() << "HP : " << monsterBeforeHp << "->" << monster->getHp() << endl;

}
