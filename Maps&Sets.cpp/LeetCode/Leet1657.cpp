#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;
        unordered_map<char, int> w1;
        unordered_map<char, int> w2;
        for(int i=0; i<word1.size(); i++){
            w1[word1[i]]++;
            w2[word2[i]]++;
        }
        if(w1.size()!=w2.size()) return false;
        // each element should be there
        for (auto e : w1) { 
            if (w2.find(e.first) == w2.end())
                return false;
        }
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for (auto e : w1) {
            m1[e.second]++;
        }
        for (auto e : w2) {
            m2[e.second]++;
        }
        if (m1.size() != m2.size())
            return false;
        for (auto e : m1) {
            // if the frequency of a character in word1 is not present in word2
            if (m2.find(e.first) == m2.end())
                return false;
            // if the frequency of a character in word1 is not equal to the
            // frequency of the same character in word2
            if (m2[e.first] != e.second)
                return false;
        }
        return true;
    }
};