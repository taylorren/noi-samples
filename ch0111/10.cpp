#include <bits/stdc++.h>
using namespace std;

int l,n,m, positions[10000001];

bool valid(int mid)
{
    int t=0, count=0;

    for(int i=1;i<=n;i++)
    {
        if(positions[i]-t<mid)
        {
            count++;
        }
        else 
        {
            t=positions[i];
        }
    }
    if(l-t<mid)
    {
        count++;
    }

    return count<=m;
}

int main()
{
    cin>>l>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>positions[i];
    }

    int s=0, e=l, mid;
    int result;

    while(s+1<e)
    {
        mid=(s+e)/2;
        if(valid(mid))
        {
            s=mid;
            result=mid;
        }
        else{
            e=mid;
        }
    }

    cout<<result<<endl;

    return 0;
}
