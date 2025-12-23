#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 八皇后问题 - 输出第b个解
 * 思路：
 * 1. 使用DFS生成所有92个解
 * 2. 将解按整数大小排序
 * 3. 输出第b个解
 * 优化：
 * - 使用一维数组queens[i]表示第i行的皇后放在第queens[i]列
 * - 使用三个数组标记已占用的列、主对角线、副对角线
 */

const int N = 8;
vector<int> solutions;  // 存储所有解（每个解转为整数）

// 检查在(row, col)位置放置皇后是否安全
bool isSafe(const vector<int>& queens, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        // 检查列冲突
        if(queens[i] == col)
            return false;
            
        // 检查对角线冲突
        if(abs(queens[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// 将一个解转换为整数
int solutionToInt(const vector<int>& queens)
{
    int result = 0;
    for(int i = 0; i < N; i++)
    {
        result = result * 10 + queens[i] + 1;  // +1因为要转成1-8
    }
    return result;
}

// DFS生成所有解
void solve(vector<int>& queens, int row)
{
    if(row == N)
    {
        // 找到一个解，转换为整数并存储
        solutions.push_back(solutionToInt(queens));
        return;
    }
    
    for(int col = 0; col < N; col++)
    {
        if(isSafe(queens, row, col))
        {
            queens[row] = col;
            solve(queens, row + 1);
        }
    }
}

int main()
{
    // 生成所有解
    vector<int> queens(N, 0);
    solve(queens, 0);
    
    // 按整数大小排序
    sort(solutions.begin(), solutions.end());
    
    // 处理查询
    int n;
    cin >> n;
    while(n--)
    {
        int b;
        cin >> b;
        cout << solutions[b-1] << endl;  // b从1开始
    }
    
    return 0;
}