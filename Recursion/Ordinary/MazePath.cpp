#include<all>

int maze(int x, int y)
{
    if (x == 1 || y == 1)
    {
        return 1;
    }
    return maze(x - 1, y) + maze(x, y - 1);
}

void PrintPath(int x, int y, string s)
{
    if (x == 1 && y == 1)
    {
        cout << s << endl;
    }
    if (x < 1 || y < 1)
    {
        return;
    }
    PrintPath(x - 1, y, s + 'R');
    PrintPath(x, y - 1, s + 'D');
    return;
}

int main()
{
    cout << "Enter the Destination Coordinate : " << endl;
    int x, y;
    cin >> x >> y;
    cout << "The No. of ways is : " << maze(x, y)<<endl;
    PrintPath(x, y, "");
}