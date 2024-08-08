#include <bits/stdc++.h>
using namespace std;

class Gun
{
public:
    int ammo;
    int damage;
    int scope;
};

class Player
{
private:
    class Helmet
    {
        int hp;
        int level;

    public:
    //  setter
        void setHp(int hp)
        {
            this->hp = hp;
        }
        void setLevel(int level)
        {
            this->level = level;
        }
        
        //  getter
        int getHp()
        {
            return hp;
        }
        int getLevel()
        {
            return level;
        }
    };
    int health;
    int age;
    int score;
    bool alive;
    Gun gun;
    Helmet helmet;

public:
    //  getter
    int getHealth()
    {
        return health;
    }
    int getAge()
    {
        return age;
    }
    int getScore()
    {
        return score;
    }
    bool IsAlive()
    {
        return alive;
    }
    Gun getGun()
    {
        return gun;
    }
    void getHelmet()
    {
        cout << helmet.getHp() << endl;
        cout << helmet.getLevel() << endl;
    }

    //  setter
    void setHealth(int health)
    {
        this->health = health;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setScore(int score)
    {
        this->score = score;
    }
    void setIsAlive(bool alive)
    {
        this->alive = alive;
    }
    void setGun(Gun gun)
    {
        this->gun = gun;
    }
    void setHelmet(int level)
    {
        Helmet *helmet = new Helmet;
        helmet->setLevel(level);
        int health;
        if (level == 1)
            health = 25;
        else if (level == 2)
            health = 50;
        else if (level == 3)
            health = 100;
        else
            cout << "Error";
        helmet->setHp(health);
        this->helmet = *helmet;
    }
};

int adddScore(Player a, Player b)
{
    return a.getScore() + b.getScore();
}

int main()
{
    Player karan, arun;
    Gun AMW;
    AMW.ammo = 1;
    AMW.damage = 1000;
    AMW.scope = 10;
    karan.setScore(100); //  compile-time, static allocation.
    arun.setScore(80);   //  object creation, statictically.

    Player *kaushal = new Player; //  run-time, dynamic allocation.

    // Player harshit = kaushal->

    // kaushal->setScore(20);
    // kaushal->setAge(18);
    // kaushal->setIsAlive(true);
    // kaushal->setHealth(100);

    kaushal->setScore(20);
    kaushal->setAge(18);
    kaushal->setIsAlive(true);
    kaushal->setHealth(100);
    kaushal->setGun(AMW);
    kaushal->setHelmet(3);
    // kaushal->getHelmet();
    Gun gun123 = kaushal->getGun();

    // cout << gun123.damage;
    // Player players[3] = {karan, arun, *kaushal};
    // cout << players[0].getScore() << endl;
    Player *players[3] = {&karan, &arun, kaushal};
    cout << players[0]->getScore() << endl;
}