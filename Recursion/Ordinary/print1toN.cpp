#include <all>
void print(int n, int i)
{
    if (i>n) // base case
    {
        return;
    }
    cout << i << " ";// work
    print(n, i + 1);// call
}

int main()
{
    int n;
    cin >> n;
    print(n, 1);
}