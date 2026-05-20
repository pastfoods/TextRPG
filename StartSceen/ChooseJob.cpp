#include "Job.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Rogue.h"
#include <iostream>
using namespace std;


Player* Job::chooseJob(string name, int hp, int mp, int power, int defence)
{
    cout << "< Job Selection >" << endl;
    cout << name << ", choose your job!" << endl;
    cout << "1. Warrior   2. Mage   3. Rogue   4. Archer" << endl;
    while (true)
    {
        cout << "Choose :";
        cin >> InputChoose;
        switch (InputChoose)
        {
        case 1:
            cout << "* You became a Warrior!(HP + 30)"<<endl;
            cout << "* Slash Sword!" << endl;
            return new Warrior(name, hp, mp, power, defence);
        case 2:
            cout << "* You became a Mage! (MP +30)" << endl;
            cout << "* Fires a fireball!" << endl;
            return new Mage(name, hp, mp, power, defence);
        case 3:
            cout << "* You became a Rogue! (ATK +30)" << endl;
            cout << "* Throw knife!" << endl;
            return new Rogue(name, hp, mp, power, defence);
        case 4:
            cout << "* You became a Archer! (DEF +30)" << endl;
            cout << "* Shoot Arrows!" << endl;
            return new Archer(name, hp, mp, power, defence);
        default:
            cout << "choose 1~4" << endl;
        }
    }
}