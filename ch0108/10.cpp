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

void matrix_transpose(int a[MAX][MAX], int n, int m, int b[MAX][MAX])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            b[j][i] = a[i][j];
        }
    }
}

void output(int matrix[MAX][MAX], int m, int n)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    int a[MAX][MAX], b[MAX][MAX];

    input(n, m, a);

    // We can do this by simply output the matrix in a different way
    // but it is suggested to do a real transpose
    //matrix_transpose(a, n, m, b);

    output(a, m, n);

    return 0;
}
