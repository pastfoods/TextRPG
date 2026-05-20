#pragma once
#include <string>
class Player;

class Monster
{
private:
protected:
    std::string name;
    std::string dropItemName;
    int dropItemPrice;
    int hp;
    int maxhp;
    int power;
    int defence;
    int expReward;
public:

    std::string getName();
    std::string getDropItemName();
    int getHp();
    int getPower();
    int getDefence();
    int getDropItemPrice();
    int getMaxHp();
    int getExpReward();

    void setHp(int hp);
    void setPower(int power);
    void setDefence(int defence);
    

    void attack(Player* player);


};


