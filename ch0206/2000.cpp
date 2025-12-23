 #include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=3001;
const int maxn=0x7fffff;

void read(int &n)
{
    char c='+';int x=0;bool flag=0;
    while(c<'0'||c>'9')
    {c=getchar();if(c=='-')flag=1;}
    while(c>='0'&&c<='9')
    {x=x*10+c-48;c=getchar();}
    flag==1?n=-x:n=x;
}

int a[MAXN],b[MAXN];
int n,m;
int pre[MAXN];
int tot;

struct node
{
    int l;
    vector<int>v;
    node()
    {
        l=0;
    }
}dp[MAXN];

int main()
{
    read(m);
    for(int i=1;i<=m;i++)
        read(a[i]);
    read(n);
    for(int i=1;i<=n;i++)
        read(b[i]);
    
    for(int i=1;i<=n;i++)
    {
        node mx;
        for(int j=1;j<=m;j++)
        {
            if(b[i]>a[j]&&dp[j].l>mx.l)
                mx=dp[j];
            if(b[i]==a[j])
            {
                dp[j].l=mx.l+1;
                dp[j].v=mx.v;
                dp[j].v.push_back(b[i]);
            }
        }
    }
    
    node ans=dp[1];
    for(int i=2;i<=m;i++)
        if(dp[i].l>ans.l)
            ans=dp[i];

    printf("%d\n",ans.l);
    for(int i=0;i<ans.v.size();i++)
        printf("%d ",ans.v[i]);
    
    return 0;
}