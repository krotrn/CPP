#include<all>
void TOH(int n, char s, char h, char d)
{
    if (n == 0) return;
    TOH(n - 1, s, d, h);
    cout << s << " -> " << d << endl;
    TOH(n - 1, h, s, d);
}

int main()
{
    cout << "Enter the no. of Level : ";
    int n;
    cin >> n;
    TOH(n,'A','B','C');
}