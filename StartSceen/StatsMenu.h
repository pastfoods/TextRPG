#pragma once
#include "Start.h"
#include "Inventory.h"

class StatsMenu: public Start
{
public:
    void showStatsMenu();
    void HP_UP();
    void MP_UP();
    void Attack_Double_UP();
    void Defense_Double_UP();
    void init(int* p_HPPotion, int* p_MPPotion); 

    int InputChoose;
    int HP_Potion;
    int MP_Potion;
    bool isGameStart;

    Inventory* inventory;
    StatsMenu(Inventory* invenotry);
private:
    int* p_HPPotion;  
    int* p_MPPotion;
};