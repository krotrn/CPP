#include <all>
string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string str = countAndSay(n - 1);
    string s = "";
    char ch = str[0];
    int frq = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (ch == str[i])
            frq++;
        else
        {
            s += (to_string(frq) + ch);
            frq = 1;
            ch = str[i];
        }
    }
    s += (to_string(frq) + ch);
    return s;
}
int main()
{
    cout << "Enter the n : ";
    int n;
    cin >> n;
    cout << countAndSay(n);
}