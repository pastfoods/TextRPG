#pragma once
#include <string>
#include "Player.h"
class Job
{
public:
     Player* chooseJob(std::string name, int hp, int mp, int power, int defence);
protected:
    int InputChoose;
    std::string name;
    std::string job;
    int level;
    int hp;
    int mp;
    int power;
    int defence;
};