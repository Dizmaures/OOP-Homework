#include <iostream>
#include <string>

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
    quality = quality + 2;
     if (quality > 6) 
    {
         quality = 6;
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
}
int Shield::Block()
{
        int block = size * protection;
    Destruction();
    return block;
}

void Shield::Destruction()
{
        if (size > 0)
    {
        size --;
    }
}

void Shield::Repair()
{
if (size < 4)
    {
        size = size + 2;
    }
}

int Shield::GetSize()
{
return size;
}
int Shield::GetProtection()
{
return protection;
}

class Character
{
public:
    Character::Character(string n, int l, int str, int sw_w, int sw_q, int sh_s, int sh_p);
    bool Hit (int damage);
    int Attack();
    int Defence();
    int GetLife();
    void Go(char direction);
    void Print();
    ~Character();

private:
    string name;
    int life;
    int strength;
    char path[11]; //10 soli + 1 vieta beigu ziimei
    int stepCount; // solus skaits lai zinatu kuraa vieta masiivaa rakstiit
    Sword sw; // zobena objeks
    Shield sh; // vairoga objekts
};

Character::Character(string n, int l, int str, int sw_w, int sw_q, int sh_s, int sh_p)
    : sw(sw_w, sw_q), sh(sh_s, sh_p)
{
    name = n;
    life = (l < 0) ? 0 : l; // Dziviba nevar but negativa
    strength = str;
    stepCount = 0; // Sakuma veikti 0 solji

    for (int i = 0; i < 10; i++)
    {
        path[i] = '-';
    }
    path[10] = '\0'; // Masiva beigu pazime
}

bool Character::Hit(int damage)
{
    life = life - damage;
    if (life < 0)
    {
        life = 0;
    }
    if (life > 0)
        return true;
    else if (life == 0)
        return false;
    
}

int Character::Attack()
{

}
