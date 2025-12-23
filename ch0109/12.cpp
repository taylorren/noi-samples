#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m[100001];
    int plateau=-1;

    int x,len=1;

    cin>>n;

    m[0]=-1e8;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
        if(m[i]==m[i-1])
        {
            len++;
        }
        else
        {
            len=1;
        }

        if(plateau<len)
        {
            plateau=len;
        }
    }

    cout<<plateau<<endl;
    return 0;
}