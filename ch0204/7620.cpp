#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 读入所有区间
    vector<pair<int, int>> intervals(n);
    for(auto& [left, right] : intervals)
    {
        cin >> left >> right;
    }

    // 按左端点排序
    sort(intervals.begin(), intervals.end());

    // 初始化合并区间的边界
    int merged_min = 10005;
    int merged_max = 0;
    bool can_merge = true;

    // 尝试合并所有区间
    for(int i = 0; i < n && can_merge; i++)
    {
        if(merged_min > merged_max)
        {
            // 第一个区间
            merged_min = intervals[i].first;
            merged_max = intervals[i].second;
        }
        else if(intervals[i].first <= merged_min && intervals[i].second >= merged_min)
        {
            // 新区间可以扩展左边界
            merged_min = intervals[i].first;
            merged_max = max(merged_max, intervals[i].second);
        }
        else if(intervals[i].first >= merged_min && intervals[i].first <= merged_max)
        {
            // 新区间可以扩展右边界
            merged_max = max(merged_max, intervals[i].second);
        }
        else
        {
            // 无法合并
            can_merge = false;
        }
    }

    if(can_merge)
    {
        cout << merged_min << " " << merged_max << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}