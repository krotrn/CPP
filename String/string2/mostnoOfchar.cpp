#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    cout << "Enter the string : ";
    string s;
    getline(cin, s);
    vector<int> v(26);

    for (int i = 0; i < s.size(); i++){
        v[(int)s[i] - 97]++;
    }

    int c = 0;

    for (int i = 0; i < v.size(); i++){
        if(c<v[i]){
            c = v[i];
        }
    }
    for (int i = 0; i < v.size(); i++){
        if(c == v[i]){
            cout << (char)(i + 97) << " " << c << endl;
        }
    }
    // int c = 0;
    // int max = 0;
    // char t;
    // for (int i = 0; i < s.size()-1; i++){
    //     c = 1;
    //     for (int j = i + 1; j < s.size();j++){
    //         if(s[i] == s[j] && s[i] != 0){
    //             c++;
    //         }
    //     }
    //     if(c>max){
    //         max = c;
    //     }
    // }
    // for (int i = 0; i < s.size()-1; i++){
    //     c = 1;
    //     for (int j = i + 1; j < s.size();j++){
    //         if(s[i] == s[j] && s[i] != 0){
    //             c++;
    //         }
    //     }
    //     if(c==max){
    //         cout<<s[i]<<" "<<max;
    //     }
    // }
}