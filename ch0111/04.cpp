#include <bits/stdc++.h>
using namespace std;

long long b[10001], res, n, s;
double t;

long long ts(int x)
{
    long long int num = 0;
    for (int i = 1; i <= n; i++)
    {
        num += b[i] / x;
    }
    return num;
}

int f(int l, int r)
{
    int mid = (l + r) / 2;
    if (r - l <= 1)
    {
        return l;
    }
    if (ts(mid) >= s)
    {
        return f(mid, r);
    }
    else
    {
        return f(l, mid);
    }
}

int main()
{
    cin >> n >> s;

    for (int i = 1; i <= n; i++)
    {
        cin>>t;
        b[i]=t*100+0.1;
    }

    if(ts(1)<s)
    {
        res=0;
    }
    else if (ts(1e8)>=s)
    {
        res=1e8;
    }
    else 
    {
        res=f(1,1e8);
    }

    cout<<fixed<<setprecision(2)<<res/100.0+0.0001;

    return 0;
}
