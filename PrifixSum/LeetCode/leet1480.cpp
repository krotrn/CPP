#include <all>

vector<int> runningSum(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
        nums[i] = nums[i - 1] + nums[i];
    return nums;
}

int main()
{
    cout << "Enter the No. of Element : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> v1 = runningSum(v);
    for(int e : v)
        cout << e << " ";
}