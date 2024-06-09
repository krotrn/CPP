#include <all>

// int longestOnes(vector<int> &nums, int k)
// {
//     int maxlen = INT_MIN;
//     int flip = 0;
//     int i = 0;
//     int j = 0;
//     while (j < nums.size())
//     {
//         if (nums[j])
//             j++;
//         else
//         {
//             if (flip < k)
//             {
//                 flip++;
//                 j++;
//             }
//             else
//             {
//                 maxlen = max(maxlen, j - i);
//                 while (nums[i])
//                     i++;
//                 i++;
//                 j++;
//             }
//         }
//     }
//     maxlen = max(maxlen, j - i);
//     return maxlen;
// }

int longestOnes(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    int maxlen = 0;
    int z = 0;
    while (j < nums.size())
    {
        if (nums[j] == 0)
            z++;
        if (z > k)
        {
            while (nums[i] && i <= j)
                i++;
            i++;
            z--;
        }
        j++;
        maxlen = max(maxlen, j - i);
    }
    return maxlen;
}

int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Enter the no. of Allowed flip : ";
    int k;
    cin >> k;
    cout << "The longest one's is : " << longestOnes(v, k);
}