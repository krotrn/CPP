#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {
            auto first = pq.top(); // Get the most frequent character
            pq.pop();

            if (!ans.empty() && ans.back() ==first.second){ // If last char is the same as current char
                if (pq.empty())
                    break; // If no other character left, we cannot add more

                auto second = pq.top(); // Get the second most frequent character
                pq.pop();

                ans += second.second; // Append the second character to result
                if (second.first-- > 1)
                    pq.push(second); // If there's more of the second character, push it back
                pq.push(first); // Push the first character back for later use
            } else {
                int use = min(2, first.first); // We can use 1 or 2 occurrences of this character
                ans.append(use, first.second); // Append the character
                if ((first.first -= use) > 0)
                    pq.push(first); // Push back if there are any left
            }
        }

        return ans;
    }
};