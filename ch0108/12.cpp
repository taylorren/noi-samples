#include <bits/stdc++.h>

using namespace std;

const int MAX = 25;

void input(int m, int n, char mat[MAX][MAX])
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
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

bool deep_equal(int m, int n, char a[MAX][MAX], char b[MAX][MAX])
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void matrix_rotate_clockwise(char a[MAX][MAX], int n, int m, char b[MAX][MAX])
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i][j] = a[n - j + 1][i];
        }
    }
}

void matrix_rotate_counter_clockwise(char a[MAX][MAX], int n, int m, char b[MAX][MAX])
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i][j] = a[j][n - i + 1];
        }
    }
}

void matrix_center_mirror(char a[MAX][MAX], int n, int m, char b[MAX][MAX])
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i][j] = a[n - i + 1][n - j + 1];
        }
    }
}

int main()
{

    int n;
    cin >> n;

    char a[MAX][MAX], b[MAX][MAX] = {0};

    input(n, n, a);
    input(n, n, b);

    char tmp[MAX][MAX];

    int res=5;
    // Case 1
    matrix_rotate_clockwise(a, n, n, tmp);
    if (deep_equal(n, n, tmp, b))
    {
        res=1;
        goto end;
    }
    matrix_rotate_counter_clockwise(a, n, n, tmp);
    if (deep_equal(n, n, tmp, b))
    {
        res=2;
        goto end;
    }
    matrix_center_mirror(a, n, n, tmp);
    if (deep_equal(n, n, tmp, b))
    {
        res=3;
        goto end;        cout << 3 << endl;
    }
    if (deep_equal(n, n, a, b))
    {
        res=4;
        goto end;
    }

end: 
    cout << res << endl;
    return 0;
}

