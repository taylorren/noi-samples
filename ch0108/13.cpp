#include <bits/stdc++.h>

using namespace std;

const int MAX = 250;

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

void output(int m, int n, int matrix[MAX][MAX])
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

void blur(int n, int m, int a[MAX][MAX], int b[MAX][MAX])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1||i==n||j==1||j==m)
            {
                b[i][j]=a[i][j];
            }
            else 
            {
                b[i][j]=round((a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1]+a[i][j])/5.0);
            }
        }
    }
}

int main()
{

    int n,m;
    cin >> n>>m;

    int a[MAX][MAX];
    int b[MAX][MAX];

    input(n, m, a);
    
    blur(n,m,a, b);

    output(n,m,b);
    
    return 0;
}

