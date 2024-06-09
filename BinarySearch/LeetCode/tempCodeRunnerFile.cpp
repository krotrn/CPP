bool check(vector<int> &v, int d, int c)
{
    int n = v.size();
    int m = c;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum >= m)
        {
            count++;
            sum = v[i];
        }
    }
    if (count <= d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int shipWithinDays(vector<int> &weights, int days)
{
    int max = INT_MIN;
    int sum = 0;
    for (int e : weights)
    {
        if (max < e)
        {
            max = e;
        }
        sum += e;
    }
    int l = max, h = sum, m;
    while (l <= h)
    {
        m = l + ((h - l) / 2);
        if (check(weights, days, m))
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return m;
}