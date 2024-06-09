#include<iostream>
#include<vector>
using namespace std;
int main(){
    // vector<vector<int>> v;
    // vector<vector<int>> v
    // vector<vector<int>> v(m)
    // vector<vector<int>> v(1, vector<int> ());
    vector<vector<int>> v(3, vector<int>(4, 2)); 
    // vector<int> v1;
    // vector<int> v2;
    // vector<int> v3;
    // v1.push_back(1);
    // v1.push_back(2);
    // v1.push_back(3);
    // v2.push_back(5);mc
    // v2.push_back(6);
    // v3.push_back(7);
    // v3.push_back(8);
    // v3.push_back(9);
    // v3.push_back(10);
    // v.push_back(v1);
    // v.push_back(v2);
    // v.push_back(v3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << v[i].size() << " ";
        }
        cout << endl;
    }
    cout << v.size() << "x" << v[0].size();
    cout<<endl;
}