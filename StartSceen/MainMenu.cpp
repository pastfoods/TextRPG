#include "MainMenu.h"
#include "Inventory.h"
#include "Battle.h"
#include "PotionShop.h"
#include <iostream>
using namespace std;


MainMenu::MainMenu(Inventory* inventory)
{
    this->inventory = inventory;
}

void MainMenu::showMainMenu(Battle& battle,PotionShop& potion)
{
    
    while (true)
    {
        if (battle.isGameOver || battle.isGameClear)
        {
            return;
        }
        cout << endl << "=== Main Menu ===" << endl;
        cout << "1. Enter Dungeon" << endl;
        cout << "2. Check Inventory" << endl;
        cout << "3. Enter PotionShop" << endl;
        cout << "0. Quit" << endl;

        cout << "Choose: ";
        cin >> InputChoose;
        switch (InputChoose)
        {
        case 0:
            cout << "Quit" << endl;
            return;
        case 1:
            cout << "Enter Dungeon" << endl;
            battle.startBattle();
            break;
        case 2:
            cout << "Check Inventory" << endl;
            inventory->itemInventory.SortItems();
            inventory->showInventory();
            break;
        case 3:
            cout << "Enter PotionShop" << endl;
            potion.showPotionShop();
            break;
        default:
            cout << "Choose 0~3" << endl;
        }
    }
}
