/*
算法：贪心算法
难度：★★☆☆☆ (2星)
描述：堆叠问题，给定N个高度和目标高度B，求最少需要多少个高度来达到或超过B
算法分析：
1. 贪心策略：优先选择最高的
2. 从大到小排序后依次累加
3. 时间复杂度：O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    long long B;
    cin >> N >> B;

    vector<int> heights(N);
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }

    // Sort heights in descending order
    sort(heights.rbegin(), heights.rend());

    long long totalHeight = 0;
    int count = 0;

    // Accumulate heights until we reach or exceed B
    for (int height : heights)
    {
        totalHeight += height;
        count++;
        if (totalHeight >= B)
        {
            break;
        }
    }

    // Output the minimum number of cows needed
    cout << count << endl;

    return 0;
}