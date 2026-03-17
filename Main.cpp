#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Sword
{
public:
    Sword(int weight, int quality);
    int Damage();
    void WearAndTear();
    void Sharpen();
    int GetWeight();
    int GetQuality();

private:
    int weight; //(2-5)
    int quality; //(1-6)
};

Sword::Sword(int weight, int quality)
{
    if (weight < 2)
         weight = 2;
    else if (weight > 5)
        weight = 5;
    
   this->weight = weight;

   if (quality < 1)
        quality = 1;
    else if (quality > 6)
        quality = 6;
    this->quality = quality;
}

int Sword::Damage()
{
    int damage = weight * quality;
    WearAndTear();
    return damage;
}

void Sword::WearAndTear()
{
    if (quality > 1)
    {
        quality--;
    }
}

void Sword::Sharpen()
{
    if (quality < 5)
    {
        quality = quality + 2;
    }
}

int Sword::GetWeight()
{
    return weight;
}

int Sword::GetQuality()
{
    return quality;
}


class Shield
{
public:
    Shield(int size, int protection);
    int Block();
    void Destruction();
    void Repair();
    int GetSize();
    int GetProtection();

private:
    int size; // 0-4
    int protection; // 1-4
};

Shield::Shield(int size, int protection) //size un protection parametri
{
    if (size < 0)
        size = 0;
    else if (size > 4)
        size = 4;

    this->size = size;

    if (protection < 1)
        protection = 1;
    else if (protection > 4)
        protection = 4;

    this->protection = protection;

int Shield::Block()
    int block = size * protection;
    Destruction();
    return block;

void Shield::Destruction()
    if (size > 0)
    {
        size --;
    }

void Shield::Repair()
    if (size < 3)
    {
        size = size + 2;
    }

int Shield::GetSize()
    return size;

int Shield::GetProtection()
    return protection;
}

class Character
{
public:
    Character(string name, int life, int strength, int sw, int sh);
    bool Hit (int);
    int Attack();
    int Defence();
    int GetLife();
    void Go(char);
    void Print();
    ~Character();

private:
    string name;
    int life;
    int strength;
    char path[10];
    Sword sw;
    Shield sh;
}
