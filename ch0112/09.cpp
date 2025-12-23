#include <bits/stdc++.h>
using namespace std;

int orig[1001][1001];
int temp[1001][1001];
int n, m;

void transform(char c)
{
    switch (c)
    {
    case 'A':
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                temp[j][n - i + 1] = orig[i][j];
            }
        }
        swap(m, n);
        break;
    case 'B':
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                temp[m - j + 1][i] = orig[i][j];
            }
        }
        swap(m, n);
        break;
    case 'C':
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                temp[i][m - j + 1] = orig[i][j];
            }
        }
        break;
    case 'D':
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                temp[n-i+1][j] = orig[i][j];
            }
        }
        break;
    default:
        break;
    }

    memcpy(orig, temp, sizeof(orig));
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> orig[i][j];
        }
    }

    string trans;
    cin >> trans;

    for (auto &c : trans)
    {
        transform(c);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<orig[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
