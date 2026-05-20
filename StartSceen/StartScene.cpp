#include <iostream>
#include "Start.h"
using namespace std;

void Start::ShowTitle()
{
    cout << "===========================================" << endl;
    cout << "[Dungeon Escape Text RPG]" << endl;
    cout << "===========================================" << endl << endl;
};


void Start::InputInformation()
{
    cout << "Enter your hero's name:";
    cin >> name;
    while (true)
    {
        cout << endl << "Enter HP and MP: ";
        cin >> stats[0];
        cin >> stats[1];
        if (stats[0] > 50 && stats[1] > 50)
        {
            break;
        }
        else
        {
            cout << "HP or MP is too low. Try again.";
        }
    }
    while (true)
    {
        cout << "Enter Attack and Defense : ";
        cin >> stats[2];
        cin >> stats[3];
        if (stats[2] > 50 && stats[3] > 50)
        {
            break;
        }
        else
        {
            cout << "Attack or Defense is too low. Try again."<<endl;
        }
    }
};

void Start::PrintStatus()
{
    cout << endl << "====================================" << endl;
    cout << name << "'s Stats" << endl;
    cout << "====================================" << endl;
    cout << "HP: " << stats[0] << "\t MP:" << stats[1] << endl;
    cout << "Attack: " << stats[2] << "\t Defense: " << stats[3] << endl;
    cout << "====================================" << endl;

};