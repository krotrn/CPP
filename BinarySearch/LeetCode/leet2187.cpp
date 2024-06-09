#include <all>
using namespace std;

bool check(vector<int> &v, long long m, int t)
{
    int n = v.size();
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        count += m / (long long)v[i];
    }
    if (count < (long long)t)
    {
        return false;
    }
    else
        return true;
}

long long minimumTime(vector<int> &time, int totalTrips)
{
    int n = time.size();
    long long l = 1;
    long long h = (long long)(totalTrips) * (long long)(*max_element(time.begin(), time.end()));
    long long mid;
    long long m;
    while (l <= h)
    {
        m = l + ((h - l) / 2);
        if (check(time, m, totalTrips))
        {
            mid = m;
            h = m - 1;
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
    cout << "Enter the no. of Busses : ";
    int n;
    cin >> n;

    cout << "Enter the no. of Trips : ";
    int t;
    cin >> t;

    cout << "Enter the no. of hour taken for one trips by Buses : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "The Minimum Hour is : " << minimumTime(v, t);
}