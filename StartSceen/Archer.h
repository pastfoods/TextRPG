#pragma once
#include "Player.h"

class Archer : public Player
{
public:
    Archer(std::string name, int maxHp, int maxMp, int power, int defence);
    void attack(Monster* monster) override;

};

