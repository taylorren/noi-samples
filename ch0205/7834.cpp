#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 11;
int n;
int nums[MAXN];
bool graph[MAXN][MAXN]; // 邻接矩阵
int color[MAXN];        // 每个顶点的颜色

// 计算最大公约数
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 检查顶点v是否可以着色为c
bool canColor(int v, int c)
{
    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] && color[i] == c)
        {
            return false;
        }
    }
    return true;
}

// 图着色，返回是否可以用k种颜色完成着色
bool graphColoring(int v, int k)
{
    // 所有顶点都已着色
    if(v == n)
        return true;

    // 尝试所有可能的颜色
    for(int c = 1; c <= k; c++)
    {
        if(canColor(v, c))
        {
            color[v] = c;
            if(graphColoring(v + 1, k))
            {
                return true;
            }
            color[v] = 0; // 回溯
        }
    }
    return false;
}

int main()
{
    // 读入数据
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // 构建图
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(gcd(nums[i], nums[j]) > 1)
            {
                graph[i][j] = graph[j][i] = true;
            }
        }
    }

    // 二分查找最小着色数
    int left = 1, right = n;
    while(left < right)
    {
        int mid = (left + right) / 2;
        fill(color, color + n, 0);
        if(graphColoring(0, mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << left << endl;
    return 0;
}