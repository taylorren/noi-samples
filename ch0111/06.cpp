#include <bits/stdc++.h>
using namespace std;
int cost[100005];


bool valid(int money, int n, int m)
{
    int sum=0, count=1;

    for(int i=1;i<=n;i++)
    {
        if(sum+cost[i]<=money)
        {
            sum+=cost[i];
        }
        else{
            sum=cost[i];
            count++;
        }
    }

    if(count<=m)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    int n, m, result;
    cin >> n >> m;

    int sum = 0, min_spending = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        sum += cost[i];
        min_spending = max(min_spending, cost[i]);
    }

    int l = min_spending, r = sum, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (valid(mid, n, m))
        {
            result = mid;
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}
