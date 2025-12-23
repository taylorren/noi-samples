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

void matrix_rotate(int a[MAX][MAX], int n, int m, int b[MAX][MAX])
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i][j] = a[n - j + 1][i];
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

    int n, m;
    cin >> n >> m;

    int a[MAX][MAX], b[MAX][MAX] = {0};

    input(n, m, a);

    // We can do this by simply output the matrix in a different way
    // but it is suggested to do a real rotate
    matrix_rotate(a, n, m, b);

    output(b, m, n);

    return 0;
}
