#include <iostream>
using namespace std;

class Cricketer
{
private:
    string name;
    int age;
    int matches;
    int run;

public:
    //  setter
    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setMatches(int matches)
    {
        this->matches = matches;
    }
    void setRun(int run)
    {
        this->run = run;
    }

    //  getter
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    int getMatches()
    {
        return matches;
    }
    int getRun()
    {
        return run;
    }
};

int main()
{
}