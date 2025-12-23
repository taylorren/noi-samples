#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int mod=1000007;
int dp[5010][5010];
int main()
{
	cin>>n>>m>>k;
	int sum;
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(int i=1;i<=m;i++)
	{
		sum=i;
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=sum;
			sum=(sum+dp[i-1][j+1])%mod;
            if(j>=k)
            {
                sum=(sum-dp[i-1][j-k]+mod)%mod;
            }
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
} 
