#include "Inventory.h"
#include "Player.h" 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Inventory::Inventory()
{
    Item hpPotion;
    hpPotion.name = "HP_Potion";
    hpPotion.price = 50;
    hpPotion.type = ItemType::Potion;

    Item mpPotion;
    mpPotion.name = "MP_Potion";
    mpPotion.price = 50;
    mpPotion.type = ItemType::Potion;

    potionTemplate.insert(make_pair("HP_Potion", hpPotion));
    potionStock.insert(make_pair("HP_Potion", 3));

    potionTemplate.insert(make_pair("MP_Potion", mpPotion));
    potionStock.insert(make_pair("MP_Potion", 3));

}
void Inventory::showInventory()
{
    int num = 1;
    cout << "[ Inventory (" << itemInventory.GetSize() << "/" << itemInventory.GetCapacity() << ") ]" << endl;
    itemInventory.PrintAllItems();
}

void Inventory::showInventory(ItemType type)
{
    cout << "[ Inventory ]" << endl;
    itemInventory.PrintTypeItems(type);
}

void Inventory::setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;


    for (int i = 0; i < count; i++) {
        itemInventory.AddItem(potionTemplate["HP_Potion"]);
    }    
    for (int i = 0; i < count; i++) {
        itemInventory.AddItem(potionTemplate["MP_Potion"]);
    }
}



 void Inventory::usePotion(string pname)
 {
     itemInventory.RemoveItem(pname);
 }

 void Inventory::usePotion(string pname, Player* player)
 {
     itemInventory.RemoveItem(pname);
     ReturnPotion(pname);

     if (pname == "HP_Potion")
     {
         int beforeHp = player->getHp();
         player->setHp(min(player->getHp() + 50, player->getMaxHp()));
         cout << "* HP Potion used!HP restored by 50 (" << beforeHp << "-> " << player->getHp() << ")" << endl;
     }
     else if (pname == "MP_Potion")
     {
         int beforeMp = player->getMp();
         player->setMp(min(player->getMp() + 50, player->getMaxMp()));
         cout << "* MP Potion used!MP restored by 50 (" << beforeMp << "-> " << player->getMp() << ")" << endl;
     }
     return;

 }

 void Inventory::DispensePotion(string name)
 {
     auto potion = potionStock.find(name);
     if (potion != potionStock.end())
     {
         if (potion->second == 0)
         {
             cout << "-> Dispense failed: out of stock!" << endl;
         }
         else
         {
             potion->second--;
             cout << "-> Dispense" << potion->first << "(stock: " << potion->second << ")" << endl;
             auto it = potionTemplate.find(name);
             if (it != potionTemplate.end())
             {
                 itemInventory.AddItem(it->second);
             }
             else
             {
                 cout << "not found" << endl;
             }
         }
         return;
     }
 }

 void Inventory::ReturnPotion(string name)
 {
     auto potion = potionStock.find(name);
     if (potion != potionStock.end())
     {
         if (potion->second == maxstock)
         {
             cout << "-> Return failed: full stock!" << endl;
         }
         else
         {
             potion->second++;
             cout << "-> Return empty bottle" << "(stock: " << potion->second << ")" << endl;
         }
         return;
     }
 }

 void Inventory::GetStock(string name)
 {
     for (const auto& potion : potionStock) {
         if (potion.first == name)
         {
             cout << potion.first << " left: " << potion.second << endl;
             return;
         }

     }
 }
