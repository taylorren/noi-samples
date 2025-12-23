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

void matrix_multiply(int a[MAX][MAX], int b[MAX][MAX], int prod[MAX][MAX], int n, int m, int k)
{
    for (int i = 1; i <= n; i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int p=1;p<=m;p++)
            {
                int tmp=a[i][p]*b[p][j];
                prod[i][j]+=tmp;
            }
        }
        
    }
}

void output(int matrix[MAX][MAX], int m, int n)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int n, m, k;
    cin >> n>>m>>k;

    int a[MAX][MAX], b[MAX][MAX], prod[MAX][MAX];

    input(n, m, a);
    input(m, k, b);

    matrix_multiply(a, b, prod, n,m,k);

    output(prod, n, k);

    return 0;
}
