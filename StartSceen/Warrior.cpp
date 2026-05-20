#include "Warrior.h"
#include <string>
#include <iostream>
using namespace std;

Warrior::Warrior(std::string name, int maxHp, int maxMp, int power, int defence): Player(name, maxHp, maxMp, power, defence)
{
    this->hp += 30;
    this->maxHp += 30;
    setJob("Warrior");
}

void Warrior::attack(Monster* monster) {
    int damage = (power - monster->getDefence());
    int monsterBeforeHp = monster->getHp();

    if (damage <= 0)
    {
        damage = 1;
    }
    cout << "[Warrior] Swings sword! -> " << damage << " damage to " << monster->getName() << "!" << endl;
    monster->setHp(monster->getHp() - damage);
    cout << monster->getName() << "HP : " << monsterBeforeHp << "->" << monster->getHp() << endl;

}