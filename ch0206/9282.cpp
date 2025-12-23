#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define mod 1000000007
LL inv[1000005] = {1, 1}, f[1000005] = {1, 1};

int main(void)
{
    int n, i;
    cin >> n;
    for(i = 2; i <= n; i++)
    {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    for(i = 2; i <= n; i++)
    {
        f[i] = ((6 * i - 3) * f[i - 1] % mod - (i - 2) * f[i - 2] % mod + mod) %
               mod * inv[i + 1] % mod;
    }
    cout << f[n - 2];
}

// https://blog.csdn.net/Jaihk662/article/details/75195098
// 超级卡特兰数