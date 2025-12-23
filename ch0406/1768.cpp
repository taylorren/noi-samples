/*
算法：动态规划 + Kadane算法
难度：★★★★☆ (4星)
描述：最大子矩阵和问题
算法分析：
1. 将2D问题转化为1D问题，通过列的压缩
2. 使用Kadane算法求最大子段和
3. 时间复杂度：O(N³)
*/

#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 105;
int matrix[MAXN][MAXN];
int n;

// 计算指定行范围内的最大子序列和
int maxSubArray(int arr[], int size)
{
    int maxSoFar = arr[0];
    int currMax = arr[0];

    for(int i = 1; i < size; i++)
    {
        currMax = max(arr[i], currMax + arr[i]);
        maxSoFar = max(maxSoFar, currMax);
    }
    return maxSoFar;
}

int maxSubMatrix()
{
    int maxSum = -127 * 100 * 100; // 最小可能值
    int temp[MAXN];

    // 遍历所有可能的行组合
    for(int startRow = 0; startRow < n; startRow++)
    {
        // 将temp数组初始化为0
        fill(temp, temp + n, 0);

        for(int endRow = startRow; endRow < n; endRow++)
        {
            // 将startRow到endRow之间的元素按列加起来
            for(int col = 0; col < n; col++)
            {
                temp[col] += matrix[endRow][col];
            }

            // 在当前行组合下，找到最大的子序列和
            int currSum = maxSubArray(temp, n);
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

int main()
{
    // 读入矩阵大小
    cin >> n;

    // 读入矩阵元素
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // 计算并输出结果
    cout << maxSubMatrix() << endl;

    return 0;
}