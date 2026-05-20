#pragma once
#include <string>
#include "Monster.h"

class Player
{
protected:
    std::string name;
    std::string job;
    int level;
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int power;
    int defence;
    int exp;
    int maxExp;

private:
    int InputChoose;
    bool check;

public:
    Player(std::string name, int maxHp, int maxMp, int power, int defence);
    virtual void attack(Monster* monster) = 0;
    virtual ~Player() {};

    void setName(std::string name);   
    void setJob(std::string job);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setMp(int mp);
    void setMaxMp(int maxMp);
    void setPower(int power);
    void setDefence(int defence);
    void setLevel(int level);
    void setExp(int exp);
    void setMaxExp(int maxExp);

    std::string getName();            
    std::string getJob();
    int getHp();
    int getMaxHp();
    int getMp();
    int getMaxMp();
    int getPower();
    int getDefence();
    int getLevel();
    int getExp();
    int getMaxExp();

    void printPlayerStatus();
    void playerLevelUp();
};