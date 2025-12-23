#include <bits/stdc++.h>
using namespace std;

int n, m;           // 大矩阵的长宽
int r, s;           // 小矩阵的长宽
int a[1001][1001];  // 大
int b[1001][1001];  // 小
int minn = 1000000; // 储存最小的绝对值
int minnow;
int row_fit; // 储存最匹配矩阵的位置
int col_fit;

void find()
{
    for (int i = 1; i <= n - r + 1; i++)
    {
        for (int j = 1; j <= m - s + 1; j++)
        {
            minnow = 0;
            for (int k = i; k <= i + r - 1; k++)
            {
                for (int l = j; l <= s + j - 1; l++)
                {
                    minnow = minnow + abs(a[k][l] - b[k - i + 1][l - j + 1]);
                }
            }
            if (minnow < minn)
            {
                row_fit = i;
                col_fit = j;
                minn = minnow;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> r >> s;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            cin >> b[i][j];
        }
    }
    find();
    for (int i = row_fit; i <= row_fit + r - 1; i++)
    {
        for (int j = col_fit; j <= col_fit + s - 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}