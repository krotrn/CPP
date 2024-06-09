#include <all>
int stair(int n)
{
    if (n < 3)
    {
        return n;
    }
    return stair(n - 1) + stair(n - 2);
}
int main()
{
    cout << "enter the number : ";
    int n;
    cin >> n;
    cout << stair(n);
}