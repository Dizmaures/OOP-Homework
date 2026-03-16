#include <iostream>

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

