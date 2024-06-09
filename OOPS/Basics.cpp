#include <all>
class Player
{
private:
    int score;
    int health;
public:
//  setter
    void setscore(int s)
    {
        score = s;
    }
    void sethealth(int h)
    {
        health = h;
    }
//  getter 
    int getscore()
    {
        return score;
    }
    int gethealth()
    {
        return health;
    }
};
int main()
{
    Player Karan;
    cout << "Enter the score : ";
    int s;
    cin >> s;
    Karan.setscore(s);
    cout << "Enter the health : ";
    int h;
    cin >> h;
    Karan.sethealth(h);
}