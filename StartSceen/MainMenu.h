#pragma once
#include "Inventory.h"
#include "PotionShop.h"
class Battle;

class MainMenu
{
public:
    int InputChoose;
    Inventory* inventory;
    MainMenu(Inventory* inventory);
    void showMainMenu(Battle& battle, PotionShop& potion);
};