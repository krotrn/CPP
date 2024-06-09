#include<all>

void print(int n)
{
    
    if(n==0)  // base case
    {
        return;
    }
    print(n - 1);// call
    cout << n << endl;// work
    return;
}

int main()
{
    int n;
    cin >> n;
    print(n);
}