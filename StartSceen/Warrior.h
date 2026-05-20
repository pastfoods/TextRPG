#pragma once
#include "Player.h"

class Warrior : public Player
{
public:
    Warrior(std::string name, int maxHp, int maxMp, int power, int defence);
    void attack(Monster* monster) override;
};
