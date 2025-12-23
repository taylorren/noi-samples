#include <iostream>
using namespace std;

const int MAXN = 105;
int n;
int matrix[MAXN][MAXN];
int sum[MAXN][MAXN][MAXN]; // sum[i][j][k]表示第i行到第j行的第k列的和

// 计算一维数组的最大子段和
int maxSubArray(int row1, int row2)
{
    int maxSum = sum[row1][row2][1], curSum = sum[row1][row2][1];
    for(int i = 2; i <= n; i++)
    {
        curSum = max(sum[row1][row2][i], curSum + sum[row1][row2][i]);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

int solve()
{
    int ans = -0x3f3f3f3f;

    // 预处理每个区间的列和
    for(int i = 1; i <= n; i++) // 上边界
    {
        for(int j = i; j <= n; j++) // 下边界
        {
            for(int k = 1; k <= n; k++) // 列
            {
                if(i == j)
                    sum[i][j][k] = matrix[i][k];
                else
                    sum[i][j][k] = sum[i][j-1][k] + matrix[j][k];
            }
        }
    }

    // 枚举上下边界求解
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            ans = max(ans, maxSubArray(i, j));
        }
    }

    return ans;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << solve() << endl;
    return 0;
}