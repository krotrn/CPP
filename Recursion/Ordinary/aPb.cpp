#include <all>
// int power(int a, int b) // T.C = O(b), S.C = O(b)stack frame
// {
//     if (b == 0)
//     {
//         if (a == 0)
//         {
//             cout << "Not Defined ";
//             return -10000;
//         }
//         return 1;
//     }
//     if (a == 0 || a == 1)
//     {
//         return a;
//     }
//     int ans = power(a, b - 1) * a;
//     return ans;
// }

int power(int a, int b) // T.C = O(log(b))  S.C = O(log(b))
{
    if (b == 0)
    {
        if (a == 0)
        {
            cout << "Not Defined ";
            return (int)"error";
        }
        return 1;
    }
    if (a == 0 || a == 1)
    {
        return a;
    }
    if (b == 1)
    {
        return a;
    }
    int ans = power(a, b / 2);
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << power(a, b);
}