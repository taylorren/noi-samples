#include <bits/stdc++.h>
using namespace std;

int area[1000005]; // 每一列的小矩形的面积，如area[0]表示横坐标为0到1之间的小矩形的面积。R最大为1000000。前置和。
int R;             // 题目中的R
int N;             // 题目中的N

int main()
{
    cin>>R>>N;
    for (int i = 0; i < N; i++)
    {
        int l, t, w, h;
        cin>>l>>t>>w>>h;
        for (int i = l; i < l + w; i++)
        {
            area[i] += h; // 矩形长度为1，所以面积就是h
        }
    }

    int l, r, mid;
    l = 0;
    r = R;
    long long area_left = 0, area_right = 0;

    while (r > l)
    {
        area_left = 0;
        area_right = 0;
        mid = (l + r) / 2;

        for (int i = 0; i < mid; i++)
        {
            area_left += area[i];
        }
        for (int i = mid; i < R; i++)
        {
            area_right += area[i];
        }

        if (r - l == 1)
        {
            if (area_left >= area_right)
            {                                            // 如果当前左边大于右边
                if (area_left + area[l] >= area_right - area[l] && // 如果把k再往右边移动以后仍然满足左边大于右边
                    (area[l] <= 0))
                {        // 如果把k再往右边移动以后面积差不增加
                    l++; // 那就移动吧
                }
                else
                {
                    break; // 不移
                }
            }
            else
            {        // 如果当前左边已经比右边小了
                l++; // 肯定要移动了
            }
        }
        else
        { // 二分中
            if (area_left <= area_right)
            { // 为了尽量让k靠右，需要用小于等于
                l = mid;
            }
            if (area_left > area_right)
            { // 为了尽量减少面积差
                r = mid;
            }
        }
    }
    while (l + 1 <= R && area[l + 1] == 0)
    { // 考虑到可能会有右边没有矩形的情况，对k进行最后的判断
        l++;
    }
    cout<<l<<endl;
    return 0;
}