#pragma once
#include "Player.h"

class Rogue : public Player
{
public:
    Rogue(std::string name, int maxHp, int maxMp, int power, int defence);
    void attack(Monster* monster) override;

};
