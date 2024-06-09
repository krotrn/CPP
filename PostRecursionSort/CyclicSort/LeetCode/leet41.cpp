#include <all>

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, correctIdx;
    while (i < n)
    {
        correctIdx = nums[i] - 1;
        if (nums[i] <= 0 || nums[i] > n || correctIdx == i || nums[i] == nums[correctIdx])
            i++;
        else
            swap(nums[correctIdx], nums[i]);
    }
    i = 0;
    while (i < n)
    {
        if (nums[i] - 1 != i)
            return i + 1;
        i++;
    }
    return n + 1;
}

int main()
{
    cout << "Enter the Element : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "The Missing No. is : " << firstMissingPositive(v);
}