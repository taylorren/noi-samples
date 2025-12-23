#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> a(6, vector<int>(6)); // 使用vector替代数组
    
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
        }
    }

    int row, col;
    for (int r = 1; r <= 5; r++)
    {
        int max = -1e9, min = 1e9;
        for (int c = 1; c <= 5; c++)
        {
            if (a[r][c] > max)
            {
                max = a[r][c];
                col = c;
            }
        }

        for (int i = 1; i <= 5; i++)
        {
            if (a[i][col] < min)
            {
                min = a[i][col];
                row = i;
            }
        }
        if (min == max)
        {
            cout << row << " " << col << " " << a[row][col] << endl;
            return 0;
        }
    }
    cout << "not found" << endl;
    return 0;
}
