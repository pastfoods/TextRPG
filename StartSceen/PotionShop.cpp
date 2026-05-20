#include "PotionShop.h"
#include "Inventory.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

PotionShop::PotionShop(Inventory* inven)
{
    inventory = inven;

    PotionRecipe hpPotion;
    hpPotion.name = "HP_Potion";
    hpPotion.ingredient0 = "Herb";
    hpPotion.ingredient1 = "Clear Water";

    potionRecipeBook.push_back(hpPotion);

    PotionRecipe mpPotion;
    mpPotion.name = "MP_Potion";
    mpPotion.ingredient0 = "Herb";
    mpPotion.ingredient1 = "Berry";


    potionRecipeBook.push_back(mpPotion);

}


void PotionShop::showPotionShop()
{
    int InputChoose;
    while (true) 
    {
        cout << endl <<"=== Potion Shop ===" << endl;
        cout << "1. Show all recipes" << endl;
        cout << "2. Search by potion name" << endl;
        cout << "3. Search by ingredient" << endl;
        cout << "4. Buy by potion name" << endl;
        cout << "0. Go back" << endl;
        cout << endl << "Choose: ";
        cin >> InputChoose;
        switch (InputChoose)
        {
        case 0:
            return;
        case 1:
            showAllRecipes();
            break;
        case 2:
            searchPotionName();
            break;
        case 3:
            searchPotioningredient();
            break;
        case 4:
            buyPotion();
            break;
        default:
            cout << "Choose 0~4" << endl;
        }
    }
}

void PotionShop::showAllRecipes()
{
    cout << endl <<"All recipes" << endl;

    for (const auto& recipe : potionRecipeBook)
    {
        recipe.PrintInfo();
    }
}

void PotionShop::searchPotionName()
{
    string pname;
    cout << endl << "Search potion name: ";
    cin >> pname;
    int find=0;
    for (const auto& recipe : potionRecipeBook)
    {
        if (recipe.name == pname)
        {
            find = 1;
            recipe.PrintInfo();
            break;
        }
       
    }
     if(find == 0)
     {
         cout << "Can't find " << pname << endl;
     }

}

void PotionShop::searchPotioningredient()
{
    string iname;
    cout << endl << "Search ingredient: ";
    cin >> iname;
    int find = 0;

    for (const auto& recipe : potionRecipeBook)
    {
        if (recipe.ingredient0 == iname)
        {
            find = 1;
            recipe.PrintInfo();
        }
        else if (recipe.ingredient1 == iname)
        {
            find = 1;
            recipe.PrintInfo();
        }

    }
    if (find == 0)
    {
        cout << "Can't find " << iname << endl;
    }
}


void PotionRecipe::PrintInfo() const
{
    cout << "-> " << name << " (" << ingredient0 << " X 1, " << ingredient1 << " X 1)" << endl;
}



void PotionShop::buyPotion()
{
    string name;
    cout << "Buy potion name:";
    cin >> name;
    inventory->GetStock(name);
    inventory->DispensePotion(name);
}