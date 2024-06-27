#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> arr(m, vector<int>(n,-1));
        ListNode *temp = head;
        int minr = 0, maxr = m - 1;
        int minc = 0, maxc = n - 1;
        while (temp!=nullptr || minr<= maxr && minc <= maxc)
        {
            for (int j = minc; j <= maxc; j++)
            {
                if(temp==nullptr)
                    return arr;
                arr[minr][j] = temp->val;
                temp = temp->next;
            }
            minr++;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = minr; i <= maxr; i++)
            {
                if(temp==nullptr)
                    return arr;
                arr[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--;
            if (minr > maxr || minc > maxc)
                break;
            for (int j = maxc; j >= minc; j--)
            {
                if(temp==nullptr)
                    return arr;
                arr[maxr][j] = temp->val;
                temp = temp->next;
            }
            maxr--;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = maxr; i >= minr; i--)
            {
                if(temp==nullptr)
                    return arr;
                arr[i][minc] = temp->val;
                temp = temp->next;
            }
            minc++;
        }
        return arr;
    }
};