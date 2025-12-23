#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m, times[10001], need[101], maxn; 
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> times[i];
    }

    for (int i = 1; i <= n; i++)
    {
        maxn = 1;
        for (int j = 2; j <= m; j++)
        {
            if (need[maxn] > need[j]) // 找出所有龙头中最快放完水的那个
            {
                maxn = j; 
            }
        }
        need[maxn] += times[i]; // 这个龙头最快换人放水，所以“需求量”加上排队中的下一个
    }

    maxn = 1;
    for (int i = 1; i <= m; i++)
    {
        maxn = need[i] > maxn ? need[i] : maxn; // 找到排队完毕最长的时间
    }
    cout << maxn;

    return 0;
}