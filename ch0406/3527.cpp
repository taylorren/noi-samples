/*
算法：深度优先搜索（DFS）
难度：★★★★☆ (4星)
描述：麻将胡牌判定
算法分析：
1. 使用DFS尝试所有可能的组合
2. 每次尝试取出一个刻子（三个相同）或顺子（三个连续）
3. 递归处理剩余牌
4. 时间复杂度：O(3^N)，其中N是牌的数量
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkThree(int a, int b, int c)
{
    return (a == b && b == c) || (a + 1 == b && b + 1 == c);
}

bool dfs(vector<int> &count, int left)
{
    if (left == 0)
    {
        return true;
    }
    for (int i = 1; i <= 9; ++i)
    {
        if (count[i] >= 3)
        {
            count[i] -= 3;
            if (dfs(count, left - 3))
            {
                return true;
            }
            count[i] += 3;
        }
        if (i <= 7 && count[i] > 0 && count[i + 1] > 0 && count[i + 2] > 0)
        {
            count[i]--;
            count[i + 1]--;
            count[i + 2]--;
            if (dfs(count, left - 3))
            {
                return true;
            }
            count[i]++;
            count[i + 1]++;
            count[i + 2]++;
        }
    }
    return false;
}

bool canHu(vector<int> &count)
{
    int sum = 0;
    for (int i = 1; i <= 9; ++i)
    {
        sum += count[i];
    }
    if (sum % 3 != 2)
    {
        return false;
    }
    for (int i = 1; i <= 9; ++i)
    {
        if (count[i] >= 2)
        {
            count[i] -= 2;
            if (dfs(count, sum - 2))
            {
                return true;
            }
            count[i] += 2;
        }
    }
    return false;
}

int main()
{
    string input;
    while (getline(cin, input))
    {
        if (input == "0")
        {
            break;
        }
        vector<int> count(10, 0);
        for (char c : input)
        {
            if (c >= '1' && c <= '9')
            {
                count[c - '0']++;
            }
        }

        int total = 0;
        for (int i = 1; i <= 9; ++i)
        {
            total += count[i];
        }

        if ((total % 3) != 2)
        {
            cout << "XIANGGONG" << endl;
        }
        else if (canHu(count))
        {
            cout << "HU" << endl;
        }
        else
        {
            cout << "BUHU" << endl;
        }
    }
    return 0;
}
