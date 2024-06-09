#include<all>
void PrAr(int a[], int n)
{
    if (n == 0) return;
    PrAr(a, n - 1);
    cout << a[n - 1] << " ";
    return;
}
int main()
{
    cout << "Enter the no. elements : ";
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int a[n];
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    PrAr(a, n);
}