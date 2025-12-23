#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int sum[50001],pre[50001],bak[50001];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i) {
            scanf("%d",&sum[i]);
            sum[i]+=sum[i-1];
        }
        pre[1]=sum[1];
        int Mn=min(sum[1],0);
        for(int i=2;i<=n;++i) {
            Mn=min(Mn,sum[i]);
            pre[i]=max(pre[i-1],sum[i]-Mn);
        }    
        bak[n]=sum[n]-sum[n-1];
        int Mx=sum[n];
        for(int i=n-1;i>1;i--) {
            Mx=max(Mx,sum[i]);
            bak[i]=max(bak[i+1],Mx-sum[i-1]);
        }
        int ans=-1e9;
        for(int i=1;i<n;++i) {
            ans=max(ans,pre[i]+bak[i+1]);
        }
        printf("%d\n",ans);
        memset(pre,0,sizeof(pre));
        memset(bak,0,sizeof(bak));
    }
    return 0;
}