#pragma once
#include <vector>
#include <string>
#include "Inventory.h"

struct PotionRecipe
{
    std::string name;
    std::string ingredient0;
    std::string ingredient1;

    void PrintInfo() const;
};

class PotionShop
{
public:
    Inventory* inventory;
    std::vector <PotionRecipe> potionRecipeBook; 
    PotionRecipe potionrecipe;
    PotionShop(Inventory* inven);
    void showPotionShop();
    void showAllRecipes();
    void searchPotionName();
    void searchPotioningredient();
    void buyPotion();
};

