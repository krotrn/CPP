#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    cout << "Input String : ";
    string s;
    getline(cin, s);
    int c = 0;
    for (int i = 0; i < s.size(); i++ )
    {
        if(s.size()==1)
        {
            break;
        }
        if(i==0){
            if (s[i] != s[i+1])
            {
                c++;
                if(s.size()==2)
                {
                    break;
                }
            }
        }
        else if (i==s.size()-1)
        {
            if(s[i]!=s[i-1])
            {
                c++;
            }
        }
        else if ((s[i] != s[i - 1] && s[i] != s[i + 1]))
        {
            c++;
        }
    }
    cout << c;
}