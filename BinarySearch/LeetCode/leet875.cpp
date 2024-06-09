#include <dir>
using namespace std;

bool check(vector<int> &v, int h, int speed)
{
    int n = v.size();
    int m = speed;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        count += v[i] / m;
        if (v[i] % m != 0)
        {
            count++;
        }
    }

    if (count <= h)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int max = *max_element(piles.begin(), piles.end());
    int l = 1;
    int hi = max;
    int m;
    int mid = max;
    while (l <= hi)
    {
        m = l + ((hi - l) / 2);
        if (check(piles, h, m))
        {
            mid = m;
            hi = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return mid;
}

int main()
{
    cout << "Enter the No.of Piles : ";
    int n;
    cin >> n;

    cout << "Enter the No. of Bananas in each piles : " << endl;
    vector<int> v(6);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Enter the no. of hour : ";
    int x;
    cin >> x;

    cout << "The minimum no. so that KOKO Eats all bananas is : " << minEatingSpeed(v, x);
}