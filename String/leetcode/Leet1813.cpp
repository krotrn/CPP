#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        vector<string> v1;
        vector<string> v2;
        string temp;
        // push words in vector
        while (ss1 >> temp)
            v1.push_back(temp);
        
        while (ss2 >> temp)
            v2.push_back(temp);
        
        // if v1 is 
        if(v1.size()==v2.size())
            return v1 == v2;
        
        // make v1 smallest
        if(v1.size()>v2.size())
            swap(v1,v2);
        // point till where words are same
        int i=0;
        while(i<v1.size() && v1[i]==v2[i]){
            i++;
        }
        // point to from where words are same till last
        int j=v1.size()-1;
        int k=v2.size()-1;
        while(j>=0 && k>=0 && v1[j]==v2[k]){
            j--;
            k--;
        }
        // if all words are same
        return i>j;
    }
};

auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){
    Solution s;
    string sentence1 = "My name is Haley";
    string sentence2 = "My Haley";
    cout << s.areSentencesSimilar(sentence1, sentence2) << endl;
    return 0;
}