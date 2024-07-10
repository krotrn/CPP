#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int noOfZero = 0, noOfOne = 0;
        for(int i = 0; i < students.size(); i++) {
            if(students[i] == 0) {
                noOfZero++;
            } else {
                noOfOne++;
            }
        }
        for(int i = 0; i < sandwiches.size(); i++) {
            if(sandwiches[i] == 0) {
                if(noOfZero == 0) {
                    return noOfOne;
                }
                noOfZero--;
            } else {
                if(noOfOne == 0) {
                    return noOfZero;
                }
                noOfOne--;
            }
        }
    }
};
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int i = 0; i < students.size(); i++)
        {
            q.push(students[i]);
        }
        int i = 0;
        int count = 0;
        while(q.size() && count != q.size())
        {
            if(q.front() == sandwiches[i])
            {
                q.pop();
                i++;
                count = 0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};