#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;

void input(int m, int n, int mat[MAX][MAX])
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void matrix_add(int a[MAX][MAX], int b[MAX][MAX], int sum[MAX][MAX], int m, int n)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = a[i][j] + b[i][j];
        }
    }
}

void output(int sum[MAX][MAX], int m, int n)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int m, n;
    cin >> m >> n;

    int a[MAX][MAX], b[MAX][MAX], sum[MAX][MAX];

    input(m, n, a);
    input(m, n, b);

    matrix_add(a, b, sum, m, n);

    output(a, m, n);

    return 0;
}
