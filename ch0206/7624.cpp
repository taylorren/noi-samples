#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int Tmax = 505, inf = 0x3f3f3f3f;
int n, m, f[Tmax][Tmax], d[Tmax], sum[Tmax], cost[Tmax][Tmax];
void init()
{
    int i, j, k, mid;
    for(i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + d[i - 1];
    for(i = 1; i <= n; i++)
        for(j = i; j <= n; j++)
        {
            mid = (i + j) >> 1;
            for(k = i; k <= j; k++)
                cost[i][j] += abs(sum[mid] - sum[k]);
        }
    memset(f, 0x3f, sizeof(f));
    return;
}
int dp(int nn, int mm)
{
    if(f[nn][mm] < inf)
        return f[nn][mm];
    if(nn <= mm)
        return f[nn][mm] = 0;
    if(mm == 1)
        return f[nn][mm] = cost[1][nn];
    int i;
    for(i = 1; i < nn; i++)
        f[nn][mm] = min(f[nn][mm], dp(i, mm - 1) + cost[i + 1][nn]);
    return f[nn][mm];
}
int main()
{
    int i;
    scanf("%d%d", &n, &m);
    for(i = 1; i < n; i++)
        scanf("%d", &d[i]);
    init();
    printf("%d", dp(n, m));
    return 0;
}
