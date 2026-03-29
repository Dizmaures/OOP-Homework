#include <iostream>
#include <string>

using namespace std;

// Klase - Sword // Sword.h
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

// Klase - Shield // Shield.h
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

//Klase - Character // Character.h
class Character
{
public:
    Character(string n, int l, int str, int sw_w, int sw_q, int sh_s, int sh_p);
    bool Hit (int damage);
    int Attack();
    int Defence();
    int GetLife();
    void Go(char direction);
    virtual void Print();
    virtual ~Character();

protected:
    string name;
    int life;
    int strength;
    char path[11]; //10 soli + 1 vieta beigu ziimei
    int stepCount; // solus skaits lai zinatu kuraa vieta masiivaa rakstiit
    Sword sw; // zobena objeks
    Shield sh; // vairoga objekts
};

class Hero : public Character
{
private:
    int experience;

public:
    // konstruktora deklaracija
    Hero(string n, int l, int str, int sw_w, int sw_q, int sh_s, int sh_p, int exp);
    void Kill(Monster &m);
    void Print() override; // jaunais Print
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
    else
        return false;
}

int Character::Attack()
{
    if (life > 0)
        return strength + sw.Damage();
    else
        return 0;
}

int Character::Defence()
{
    if (life > 0)
        return (strength / 2) + sh.Block();
    else
        return 0;
}

int Character::GetLife()
{
    return life;
}

void Character::Go(char direction)
{
    if (life > 0 && stepCount < 10)
    {
        path[stepCount] = direction;
        stepCount++;
    }
}

void Character::Print()
{
    cout << "Varonis :" << name << endl;
    if (life > 0)
    {
        cout << "Statuss: Dzivs (" << life << "HP)" << endl;
    }
    else
    {
        cout << "Statuss: Miris" << endl;
    }
cout << "Marsruts: " << path << endl;
cout << "Zobena kvalitate: " << sw.GetQuality() << endl;
cout << "Vairoga izmers: " << sh.GetSize() << endl;
cout << "-----------------------" << endl;
}

Character::~Character()
{
cout << "Game over for " << name << endl;
}


// Funkcija - Fight:
bool Fight(Character &ch1, Character &ch2)
{
    if (ch1.GetLife() > 0 && ch2.GetLife() > 0)
    {
        int damage = ch1.Attack() - ch2.Defence();

        if (damage < 0)
        damage = 0;

        ch2.Hit(damage);
        return true; // Kauja notika
    }
    return false; // Kads jau bija miris
}

//Main.cpp
int main() {
    // Izveidojam 2 speletajus
    Character p1("Maikls", 100, 20, 4, 5, 3, 4);
    Character p2("Lebrons", 50, 15, 3, 4, 2, 3);

    // Vienam ievada < 10 virzienus otram > 10
    p1.Go('w'); p1.Go('d'); // 2 soļi
    
    for(int i = 0; i < 15; i++) {
        p2.Go('s'); // Meginaas 15, bet klase atļaus tikai 10
    }

    // Kauja liidz p2 nomirst
    cout << "--- KAUJA SAKAS ---" << endl;
    while(p2.GetLife() > 0) {
        Fight(p1, p2);
        cout << "P2 dziviba: " << p2.GetLife() << endl;
    }

    // Megina velreiz iesist un likt iet mirusajam
    p2.Hit(10);
    p2.Go('w');

    // Beigaas izvada abus
    cout << endl << "--- REZULTATI ---" << endl;
    p1.Print();
    p2.Print();

    return 0;
}
