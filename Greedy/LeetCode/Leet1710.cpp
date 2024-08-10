#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < boxTypes.size(); i++)
            arr.push_back({boxTypes[i][0], boxTypes[i][1]});
        sort(arr.begin(), arr.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
            return p1.second > p2.second;
        });
        int maximumUnits = 0;
        for (int i = 0; i<arr.size(); i++)
        {
            if(arr[i].first <=truckSize)
            {
                maximumUnits += arr[i].first * arr[i].second;
                truckSize -= arr[i].first;
            }
            else
            {
                maximumUnits += truckSize * arr[i].second;
                break;
            }
        }
        return maximumUnits;
    }
};

int main()
{
    vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = 4;
    Solution s;
    cout << s.maximumUnits(boxTypes, truckSize);
    return 0;
}