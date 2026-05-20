#pragma once
#include "Player.h"
#include "Monster.h"
#include "Inventory.h"
#include "MainMenu.h"
#include <vector>


struct Room
{
    Monster* monster;
    bool Clear;
};

class Battle
{
public:
    Player* player;
    std::vector<Monster*> monsters;
    std::vector<Room> room;
    Monster* monster;
    Inventory* inventory;
    Item item;
    Battle(Player* player, std::vector<Monster*> monsters, Inventory* inventory);
    void startBattle();
    void playerGetExp();
    void showRooms();
    void bossRoom();
    void clearRoom(Monster* monster);
    bool clearCheck(int roomnum);
    bool isGameClear;
    bool isGameOver;
};

