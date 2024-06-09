#include <all>

int minSubArrayLen(int target, vector<int> &nums)
{
    int i = 0;
    int j = 0;
    int mini = INT_MAX;
    int sum = 0;
    while (j < nums.size())
    {
        sum += nums[j];
        while (sum >= target)
        {
            mini = min(mini, j - i + 1);
            sum -= nums[i++];
        }
        j++;
    }
    if (mini == INT_MAX)
        return 0;
    return mini;
}

int main()
{
    cout << "Enter the No. of Elementts : ";
    int n;
    cin >> n;
    cout << "Emter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Enter the Target : ";
    int x;
    cin >> x;
    cout << "The minimum Array length is : " << minSubArrayLen(x, v);
}