#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

class Player;
enum class ItemType { Potion, MonsterDrop };

template<typename T>
class InvenTem {
private:
    T* pItems_;
    int capacity_; // 최대 용량
    int size_;  // 현재 용량

public:

    InvenTem(int capacity = 20)
    {
        capacity_ = capacity;
        size_ = 0;
        pItems_ = new T[capacity_];
    }

    ~InvenTem()
    {
        delete[] pItems_;
    }


    void AddItem(const T& item)
    {
        pItems_[size_] = item; 
        size_++;
        if (size_ == capacity_)
        {
            std::cout << "->Inventory auto - expanded!(" << capacity_ << " -> " << capacity_ * 2 << ")" << std::endl;
            Resize(capacity_ * 2);
        }
    }

    void RemoveLastItem()
    {
        size_--;
    }
    void RemoveItem(std::string name)
    {
        for (int i = 0; i < size_; i++)
        {
            if (pItems_[i].name == name)
            {
                for (int j = i; j < size_ - 1; j++) {
                    pItems_[j] = pItems_[j + 1];
                }
                RemoveLastItem();
                return;
            }
        }
    }

    void PrintAllItems()
    {
        for (int i = 0; i < size_; i++)
        {
            std::cout << (i + 1) << ". " << pItems_[i].toString() << std::endl;
        }
    }

    void PrintTypeItems(ItemType type)
    {
        for (int i = 0; i < size_; i++)
        {
            if (pItems_[i].type == type)
            {
                std::cout << (i + 1) << ". " << pItems_[i].toString() << std::endl;
            }
        }
    }


    int GetSize()
    {
        return size_;
    }

    int GetCapacity()
    {
        return capacity_;
    }

    void Resize(int newCapacity)
    {
        T* newItems = new T[newCapacity]; // 복사용 새 배열
        for (int i = 0; i < GetSize(); i++)
        {
            newItems[i] = pItems_[i];  // 기존 배열을 복사 배열에 저장
        }
        delete[] pItems_;  // 기존 배열 삭제
        pItems_ = newItems; // pItems에 새로운 배열 저장
        capacity_ = newCapacity; // 최대 크기 조절
    }

    static bool compareByPrice(const T& a, const T& b)
    {
        return a.price < b.price;
    }
    
    void SortItems()
    {
        std::sort(pItems_, pItems_ + size_, compareByPrice);
    }

    T& operator[](int index)
    {
        return pItems_[index];
    }


};


struct Item
{
    std::string name;
    int price;
    ItemType type;

    std::string toString() const {
        return name + " (" + std::to_string(price) + "G)";
    }
};



class Inventory
{
public:
    InvenTem<Item> itemInventory;
    int maxInvnetory;
    const int maxstock = 3;


    Inventory();
    void showInventory();
    void showInventory(ItemType type);
    void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
    void usePotion(std::string pname);
    void usePotion(std::string pname,Player* player);

    std::map<std::string, int>potionStock;
    std::map<std::string, Item>potionTemplate;
    void DispensePotion(std::string name);
    void ReturnPotion(std::string name);
    void GetStock(std::string name);
};