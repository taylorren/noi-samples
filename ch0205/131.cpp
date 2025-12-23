#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 图着色问题：给每个中继器分配频道，使相邻中继器的频道不同
 * 核心算法：回溯法 + 最小着色数搜索
 * 1. 使用邻接矩阵存储中继器之间的连接关系
 * 2. 从1开始尝试不同的颜色数量，直到找到可行解
 * 3. 对于每种颜色数量，使用回溯法尝试给每个顶点着色
 * 时间复杂度：O(m^n)，其中m为颜色数，n为顶点数
 * 空间复杂度：O(n^2)，主要是邻接矩阵的空间
 */

const int MAXN = 26;
vector<vector<bool>> graph; // 邻接矩阵
vector<int> color; // 每个顶点的颜色
int n;

// 检查顶点v是否可以着色为c
// 核心思路：检查v的所有邻接顶点是否已经使用了颜色c
bool isValid(int v, int c)
{
    // 遍历所有顶点，检查是否有邻接顶点使用了颜色c
    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] && color[i] == c)
        {
            return false;
        }
    }
    return true;
}

// 回溯法尝试用maxColors种颜色给图着色
// v: 当前要着色的顶点
// maxColors: 最多可用的颜色数
// 核心思路：尝试所有可能的颜色，直到找到可行解
bool graphColoring(int v, int maxColors)
{
    // 基本情况：所有顶点都已经着色
    if(v == n)
    {
        return true;
    }

    // 尝试所有可能的颜色
    for(int c = 1; c <= maxColors; c++)
    {
        // 检查当前颜色是否可行
        if(isValid(v, c))
        {
            // 着色当前顶点
            color[v] = c;
            // 递归尝试下一个顶点
            if(graphColoring(v + 1, maxColors))
            {
                return true;
            }
            // 回溯，撤销当前着色
            color[v] = 0;
        }
    }
    return false;
}

// 寻找最小需要的颜色数
// 策略：从1开始逐步增加颜色数，直到找到可行解
int findMinColors()
{
    // 尝试所有可能的颜色数
    for(int colors = 1; colors <= n; colors++)
    {
        // 重置所有顶点的颜色
        color.assign(n, 0);
        // 尝试当前颜色数
        if(graphColoring(0, colors))
        {
            return colors;
        }
    }
    return n;
}

int main()
{
    while(cin >> n && n)
    {
        // 初始化邻接矩阵
        graph.assign(n, vector<bool>(n, false));
        cin.ignore();

        // 读入邻接关系并构建无向图
        for(int i = 0; i < n; i++)
        {
            string line;
            getline(cin, line);
            if(line.length() > 2)
            {
                for(size_t j = 2; j < line.length(); j++)
                {
                    if(isalpha(line[j]))
                    {
                        int v = line[j] - 'A';
                        graph[i][v] = true;
                        graph[v][i] = true; // 无向图，对称存储
                    }
                }
            }
        }

        // 寻找最小需要的颜色数
        int result = findMinColors();
        cout << result << " channel" << (result == 1 ? "" : "s") << " needed."
             << endl;
    }
    return 0;
}