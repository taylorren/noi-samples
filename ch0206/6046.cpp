#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 10;
const int INF = 0x3f3f3f3f;
int T, N;
int penalt[MAXN];
int sum[MAXN];
int dp[MAXN][MAXN];
int main()
{
    //    freopen("in.txt","r",stdin);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &penalt[i]);
            sum[i] = sum[i - 1] + penalt[i];
        }
        for(int l = 1; l <= N; l++)
        {
            for(int i = 1; i <= N - l + 1; i++)
            {
                int j = l + i - 1;
                dp[i][j] = INF;
                for(int k = i; k <= j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] +
                                                 penalt[k] * (l - 1) +
                                                 (sum[j] - sum[k]) * (k - i));
                }
            }
        }
        printf("%d\n", dp[1][N]);
    }
}