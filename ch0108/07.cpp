#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e9;
int n, s = 2;
int mat[N][N];

void remove_row()
{
    for (int i = 1; i <= n; i++)
    {
        int t = mat[i][1];
        for (int j = s; j <= n; j++)
            t = min(t, mat[i][j]);
        mat[i][1] -= t;
        for (int j = s; j <= n; j++)
        {
            mat[i][j] -= t;
        }
    }
}

void remove_col()
{
    for (int j = 1; j <= n; j++)
    {
        int t = mat[1][j];
        for (int i = s; i <= n; i++)
            t = min(t, mat[i][j]);
        mat[1][j] -= t;
        for (int i = s; i <= n; i++)
        {
            mat[i][j] -= t;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
        }
    }
    int ans;
    for (int i = 0; i < n - 1; i++)
    {
        cout << mat[s][s] << endl;
        remove_row();
        remove_col();
        ans = mat[s][s];
        for (int i = 1; i <= n; i++)
        {
            mat[i][s] = inf;
            mat[s][i] = inf;
        }
        s++;
    }
    cout << ans << endl;
    return 0;
}
