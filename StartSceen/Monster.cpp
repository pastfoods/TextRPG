#include "Monster.h"
#include "Player.h"
#include <string>
#include <iostream>
using namespace std;


void Monster::setHp(int hp)
{
    this->hp = hp;
}void Monster::setPower(int power)
{
    this->power = power;
}void Monster::setDefence(int defence)
{
    this->defence = defence;
}


string Monster::getName()
{
    return name;
}
string Monster::getDropItemName()
{
    return dropItemName;
}
int Monster::getHp()
{
    return hp;
}
int Monster::getMaxHp()
{
    return maxhp;
}
int Monster::getPower()
{
    return power;
}
int Monster::getDefence()
{
    return defence;
}
int Monster::getDropItemPrice()
{
    return dropItemPrice;
}
int Monster::getExpReward()
{
    return expReward;
}



void Monster::attack(Player* player)
{
    int damage;
    damage = power - player->getDefence();
    if (damage <= 0)
    {
        damage = 1;
    }

    player->setHp(player->getHp() - damage);
    cout << getName() << " attack to " << player->getName() << " " << damage << "damage!" << endl;
    
}