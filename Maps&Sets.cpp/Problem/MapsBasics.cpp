#include<bits/stdc++.h>
using namespace std;

// int main(){
//     unordered_map<string,int> m;
//     m["a"] = 1;
//     m["b"] = 2;
//     m["c"] = 3;
//     m["d"] = 4;
//     m["e"] = 5;
//     m["f"] = 6;

//     for(auto i : m){
//         cout<<i.first<<" "<<i.second<<endl;
//     }
// }
int main(){
    unordered_map<string,int> m;
    pair<string,int> p;
    p.first = "a";
    p.second = 1;
    m.insert(p); // O(1)
    p = make_pair("b",2);
    m.insert(p);
    p = make_pair("c",3);
    m.insert(p);
    p = make_pair("d",4);
    m.insert(p);
    p = make_pair("e",5);
    m.insert(p);
    p = make_pair("f",6);
    m.insert(p);
    m.erase("a");

    cout<<m.size()<<endl; // O(1)

    for(auto i : m){ // O(n)
        cout<<i.first<<" "<<i.second<<endl;
    }

    if(m.find("a") == m.end()){ // O(1)
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Found"<<endl;
    }
}