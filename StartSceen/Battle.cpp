#include "Battle.h"
#include "Monster.h"
#include "Player.h"
#include "Inventory.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Battle::Battle(Player* player, vector<Monster*> monsters,Inventory* inventory)
{
    this->player = player;
    this->monsters = monsters;
    this->monster = nullptr;
    this->inventory = inventory;

    for (auto r : monsters)
    {
        room.push_back({ r,false });
    }
}



void Battle::startBattle()
{
    int playerBeforeHp;
    int damage;
    int inputChoose;
    int inputUse;

    while (true) {
        showRooms();
        bossRoom();
        cout << "Choose Room :" << endl;
        cin >> inputChoose;
        if (clearCheck(inputChoose))
        {
            Room& selectedRoom = room[inputChoose - 1];
            this->monster = selectedRoom.monster;
            break;
        }
        else
        {
            cout << "It is an invalid input, or you need to clear the previous room first." << endl;
        }
    }

    cout << endl << "[Battle Start!] " << player->getName() << "(" << player->getJob() << ") vs " << monster->getName() << endl;

    while (player->getHp() > 0 && monster->getHp() > 0)
    {
        cout << endl << endl << "--- Player Turn ---" << endl;
        cout << "1. Attack" << endl << "2. Use Item" << endl << "Choose: ";
        cin >> inputChoose;
        switch (inputChoose)
        {
        case 1:
        {
            player->attack(monster);
            if (monster->getHp() <= 0)
            {
                monster->setHp(monster->getMaxHp());
                cout << " (Dead)" << endl << endl;
                cout << "¡Ú Victory!" << endl;
                playerGetExp();
                cout << "-> Got: " << monster->getDropItemName() << endl;
                cout << "->Saved to inventory" << endl;
                item.name = monster->getDropItemName();
                item.price = monster->getDropItemPrice();
                item.type = ItemType::MonsterDrop;
                inventory->itemInventory.AddItem(item);
                clearRoom(monster);
                if (monster->getName() == "Dragon")
                {
                    cout << "Dragon defeated!" << endl << "== = GAME CLEAR!== = " << endl;
                    isGameClear = true;
                }
                return;
            }
            break;
        }
        case 2:
        {
            inventory->showInventory(ItemType::Potion);
            cin >> inputUse;
            string useItem = inventory->itemInventory[inputUse - 1].name;
            inventory->usePotion(useItem, player);
            break;
        }
        default:
            cout << "Choose 1~2" << endl;
            break;
        }

        cout << endl << "--- Monster Turn ---" << endl;
        playerBeforeHp = player->getHp();
        monster->attack(player);
        cout << player->getName() << "HP : " << playerBeforeHp << "->" << player->getHp();
        if (player->getHp() <= 0)
        {
            cout << " (Dead)" << endl << endl;
            cout << "Defeat!" << endl << "Game Over" << endl;
            isGameOver = true;
            break;
        }

    }

}

void Battle::playerGetExp()
{
    int remainExp = 0;
    player->setExp(player->getExp() + monster->getExpReward());
    if (player->getExp() >= player->getMaxExp())
    {
        remainExp = player->getExp() - player->getMaxExp();
        player->playerLevelUp();
        player->setExp(remainExp);
        cout << "-> + " << monster->getExpReward() << "EXP!(EXP: " << player->getExp() << " / " << player->getMaxExp() << ")" << endl;
    }
    else
    {
        cout << "-> + " << monster->getExpReward() << "EXP!(EXP: " << player->getExp() << " / " << player->getMaxExp() << ")" << endl;
    }
}

void Battle::showRooms()
{
    int roomnum = 0;
    for (const auto& rooms : room)
    {
        if (rooms.monster->getName() != "Dragon")
        {
            roomnum++;
            cout << "Room " << roomnum << ": " << rooms.monster->getName() << "\t(HP " << rooms.monster->getMaxHp() << ", Attack " << rooms.monster->getPower() << ")\t";
            if (rooms.Clear)
            {
                cout << "-> Clear";
            }
            cout << endl;
        }
    }
}

void Battle::bossRoom()
{
    int clearroom = 0;
    for (const auto& rooms : room)
    {
        if (clearroom == 3)
        {
            cout << "¡Ú Boss Room Unlocked!" << endl;
            cout << "Boss " << rooms.monster->getName() << "\t(HP " << rooms.monster->getMaxHp() << ", Attack " << rooms.monster->getPower() << ")\t" << endl;
        }
        if (rooms.monster->getName() != "Dragon")
        {
            if (rooms.Clear) 
            {
                clearroom++;
            }
        }
    }
}

void Battle::clearRoom(Monster* monster)
{
    for (auto& rooms : room)
    {
        if (rooms.monster == monster)
        {
            rooms.Clear = true;
        }
    }
}

bool Battle::clearCheck(int roomnum)
{
    if (roomnum == 1)
    {
        return true;
    }
    Room& checkRoom = room[roomnum - 2];
    if (checkRoom.Clear)
    {
        return true;
    }
    return false;
}