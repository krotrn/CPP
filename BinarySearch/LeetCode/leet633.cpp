#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isperfectsquare(int x)
{
    int root = sqrt(x);
    if (root * root == x)
        return true;
    else
        return false;
}
bool judgeSquareSum(int c)
{
    int x = 0, y = c;
    while (x < y)
    {
        if (isperfectsquare(x) && isperfectsquare(y))
        {
            return true;
        }
        else if (!isperfectsquare(y))
        {
            y = (int)sqrt(y) * (int)sqrt(y);
            x = c - y;
        }
        else
        {
            x = (int)(sqrt(x) + 1) * (int)(sqrt(x) + 1);
            y = c - x;
        }
    }
    return false;
}

int main()
{
    cout << "Enter the Integer : ";
    int n;
    cin >> n;
    cout << "Is it sum of two square : ";
    if (judgeSquareSum(n) == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}