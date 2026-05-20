#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"
using namespace std;


Player::Player(string name, int maxHp, int maxMp, int power, int defence)
{
    this->name = name;
    this->maxHp = maxHp;
    this->hp = maxHp;
    this->maxMp = maxMp;
    this->mp = maxMp;
    this->power = power;
    this->defence = defence;
    this->level = 1;
    this->exp = 0;
    this->maxExp = 100;
};

void Player::setName(string name)
{
    this->name = name;
}
void Player::setJob(string job)
{
    this->job = job;
}
void Player::setHp(int hp)
{
    this->hp = hp;
}
void Player::setMaxHp(int maxHp)
{
    this->maxHp = maxHp;
}
void Player::setMp(int mp)
{
    this->mp = mp;
}
void Player::setMaxMp(int maxMp)
{
    this->maxMp = maxMp;
}
void Player::setPower(int power)
{
    this->power = power;
}
void Player::setDefence(int defence)
{
    this->defence = defence;
}
void Player::setLevel(int level)
{
    this->level = level;
}
void Player::setExp(int exp)
{
    this->exp = exp;
}
void Player::setMaxExp(int maxExp)
{
    this->maxExp = maxExp;
}



string Player::getName()
{
    return name;
}
string Player::getJob()
{
    return job;
}
int Player::getHp()
{
    return hp;
}
int Player::getMaxHp()
{
    return maxHp;
}
int Player::getMp()
{
    return mp;
}
int Player::getMaxMp()
{
    return maxMp;
}
int Player::getPower()
{
    return power;
}
int Player::getDefence()
{
    return defence;
}
int Player::getLevel()
{
    return level;
}
int Player::getExp()
{
    return exp;
}
int Player::getMaxExp()
{
    return maxExp;
}

void Player::printPlayerStatus()
{
    cout << "------------------------------------" << endl;
    cout << "Name: " << getName() << "| Job : " << getJob() << " | Lv." << getLevel() << " | Exp(" << getExp() << "/" << getMaxExp() << ")" << endl;
    cout << "HP : " << getMaxHp() << "| MP : " << getMaxMp() << "| Attack : " << getPower() << " | Defense : " << getDefence() << endl;
    cout << "------------------------------------" << endl;
}


void Player::playerLevelUp()
{
    cout << endl << "->Level Up! Lv." << getLevel() << " ->Lv." << getLevel() + 1 << endl;
    cout << "-> HP + 10, MP + 5, Attack + 5" << endl;
    setLevel(getLevel() + 1);
    setMaxHp(getMaxHp() + 10);
    setHp(getHp() + 10);
    setMaxMp(getMaxMp() + 5);
    setMp(getMp() + 5);
    setPower(getPower() + 5);
    setMaxExp(getMaxExp() + 30);
}