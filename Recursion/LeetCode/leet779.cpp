#include <all>
//  T.C = O(n)
int kthGrammar(int n, int k)
{
    if (n == 0)
        return 0;
    if (k % 2 == 0)
    {
        if (kthGrammar(n - 1, k / 2))
            return 0;
        else
            return 1;
    }
    else
        return kthGrammar(n - 1, (k / 2) + 1);
}

int main()
{
    cout << "Enter the no. of ROW : ";
    int n;
    cin >> n;
    cout << "Enter the Kth Element : ";
    int k;
    cin >> k;
    cout << "The kth Element in nth row is : " << kthGrammar(n, k);
}