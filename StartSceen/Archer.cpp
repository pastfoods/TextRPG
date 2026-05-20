#include "Archer.h"
#include <string>
#include <iostream>
using namespace std;
Archer::Archer(std::string name, int maxHp, int maxMp, int power, int defence) : Player(name, maxHp, maxMp, power, defence)
{
    this->defence += 30;
    setJob("Archer");

};

void Archer::attack(Monster* monster) {
    int damage = (power - monster->getDefence())/3;
    int monsterBeforeHp = monster->getHp();
    if (damage <= 0)
    {
        damage = 1;
    }
    cout << "[Archer] shoots Arrow! -> " << damage << " damage to " << monster->getName() << "! (X3)" << endl;
    monster->setHp(monster->getHp() - (damage*3));
    cout << monster->getName() << "HP : " << monsterBeforeHp << "->" << monster->getHp() << endl;

}