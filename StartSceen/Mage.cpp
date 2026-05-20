#include "Mage.h"
#include <string>
#include <iostream>
using namespace std;
Mage::Mage(std::string name, int maxHp, int maxMp, int power, int defence) : Player(name, maxHp, maxMp, power, defence)
{
    this->mp += 30;
    this->maxMp += 30;
    setJob("Mage");
}

void Mage::attack(Monster* monster) {
    int damage = (power - monster->getDefence());
    int monsterBeforeHp = monster->getHp();
    if (damage <= 0)
    {
        damage = 1;
    }
    cout << "[Mage] casts Fireball! -> " << damage << " damage to " << monster->getName() << "!" << endl;
    monster->setHp(monster->getHp() - damage);
    cout << monster->getName() << "HP : " << monsterBeforeHp << "->" << monster->getHp() << endl;

}
