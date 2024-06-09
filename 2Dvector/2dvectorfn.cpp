#include<iostream>
#include<vector>
using namespace std;
void change2dvector(vector<vector<int>> &v){
    v[0][1]=200;
}
void length(vector<vector<int>> &v,int i){
    cout<<v[i].capacity()<<" ";
}
int main(){
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(5);
    v2.push_back(6);

    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);
    v3.push_back(10);

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    
    cout<<v[0][1]<<" ";
    change2dvector(v);
    cout<<v[0][1]<<" ";
    length(v,0);
    length(v,1);
    length(v,2);
}