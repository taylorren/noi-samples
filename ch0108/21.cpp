#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    int a[110][110];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }

    int r=0, c=0;
    // Main diag in the upper left pane
    for (int j = 0; j < col; j++)
    {
        r = 0;
        c = j;
        while (r < row && c >= 0)
        {
            cout << a[r++][c--] << endl;
        }
    }
    // Main diag in the lower right pane, excluding from (1,n) to (n,1)
    for (int i = 1; i < row; i++)
    {
        r = i;
        c = col - 1;
        while (r < row && c >= 0)
        {
            cout << a[r++][c--] << endl;
        }
    }

    return 0;
}
