#include<all>

bool exist(vector<vector<char>> &board, string word)
{
    
}

int main()
{
    cout << "Enter the Row and Column : ";
    int r, c;
    cin >> r >> c;
    cout << "Enter the Elements : " << endl;
    vector<vector<char>> v(r, vector<char>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << "Enter the word : ";
    string s;
    cin >> s;
    cout<<exist(v,s);
}