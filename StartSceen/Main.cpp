#include "Start.h"
#include "StatsMenu.h"
#include "Player.h"
#include "Job.h"
#include "Battle.h"
#include "MainMenu.h"
#include "Inventory.h"
#include "PotionShop.h"
#include "Slime.h"
#include "Goblin.h"
#include "Orc.h"
#include "Dragon.h"
#include <vector>

int HPPotion = 0;
int MPPotion = 0;
// 전역변수

int main()
{
    Inventory inventory;
    MainMenu mainmenu(&inventory);
    StatsMenu statsmenu(&inventory);
    PotionShop potion(&inventory);
    Job job;
    statsmenu.ShowTitle();
    statsmenu.InputInformation();
    statsmenu.PrintStatus();
    inventory.setPotion(5, &HPPotion, &MPPotion);//&를 통해 주소값 전달
    statsmenu.init(&HPPotion, &MPPotion);
    statsmenu.showStatsMenu();
    Player* player = nullptr;
    player = job.chooseJob(statsmenu.name, statsmenu.stats[0], statsmenu.stats[1], statsmenu.stats[2], statsmenu.stats[3]);
    player->printPlayerStatus();
    std::vector<Monster*> monsters = { new Slime(), new Goblin(), new Orc(), new Dragon() };
    Battle battle(player, monsters, &inventory);
    mainmenu.showMainMenu(battle,potion);

    delete player;
    player = nullptr;

    return 0;
}