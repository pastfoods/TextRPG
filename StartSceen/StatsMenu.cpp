#include <iostream>
#include "Start.h"
#include "StatsMenu.h"
#include "Inventory.h"

using namespace std;
StatsMenu::StatsMenu(Inventory* inventory)
{
    this->inventory = inventory;
}

void StatsMenu::showStatsMenu()
{
    isGameStart = false;
    cout << endl <<"* You received 5 HP Potions and 5 MP Potions." << endl;

    while (!isGameStart) {
        cout << "============================================ " << endl;
        cout << "< Character Upgrade >" << endl;
        cout << "1. HP UP    2. MP UP    3. Attack x2" << endl;
        cout << "4. Defense x2  5. Show Stats  0. Start Game" << endl;
        cout << "============================================" << endl;
        cout << "Choose: ";
        cin >> InputChoose;
        switch (InputChoose)
        {
        case 1:
            HP_UP();
            continue;
        case 2:
            MP_UP();
            continue;
        case 3:
            Attack_Double_UP();
            continue;
        case 4:
            Defense_Double_UP();
            continue;
        case 5:
            PrintStatus();
            continue;
        case 0:
            cout << "Starting the game!" << endl << endl;
            isGameStart=true;
            break;
        default:
            cout << "Choose 0 ~ 5" << endl << endl;
        }
    }
}

void StatsMenu::HP_UP()
{
    if (*p_HPPotion > 0)
    {
        stats[0] += 20;
        (*p_HPPotion)--;
        inventory->usePotion("HP_Potion");
        cout << "* HP increased by 20. (HP Potion used : " << *p_HPPotion << " left)" << endl << endl;
    }
    else
    {
        cout << " Not Enough HP Potion" << endl << endl;

    }
}

void StatsMenu::MP_UP()
{
    if (*p_MPPotion > 0)
    {
        stats[1] += 20;
        (*p_MPPotion)--;
        inventory->usePotion("MP_Potion");
        cout << "* MP increased by 20. (MP Potion used : " << *p_MPPotion << " left)" << endl << endl;
    }
    else
    {
        cout << " Not Enough MP Potion" << endl << endl;

    }
}

void StatsMenu::Attack_Double_UP()
{
    stats[2] *= 2;
    cout << "* Attatck power doubled" << endl << endl;
}

void StatsMenu::Defense_Double_UP()
{
    stats[3] *= 2;
    cout << "* Defense power doubled" << endl << endl;
}

void StatsMenu::init(int* p_HPPotion, int* p_MPPotion)
{
    this->p_HPPotion = p_HPPotion;
    this->p_MPPotion = p_MPPotion;
}

/*
포인터를 쓰지 않고 매개변수만 넘겼을 때 값이 바뀌지 않는 이유를 설명하기
매개변수로 넘기는 경우 값을 복사해서 새로 만들어서 넘기는 거고
포인터로 넘기는 경우 주소값을 넘겨 같은 대상을 참조하고 있으므로 수정시 값이 같이 변한다
*/