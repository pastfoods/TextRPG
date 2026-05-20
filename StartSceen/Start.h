#pragma once  
#include <string>
class Start
{
public:
    void ShowTitle();
    void InputInformation();
    void PrintStatus();

    std::string name;
    static const int SIZE = 4;
    int stats[SIZE] = { 0 };
};




