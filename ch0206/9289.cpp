#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10, mod = 1000000;
int T, A, L, R;
int num[MAXN], f[MAXN], sum[MAXN], s;

int main()
{
    cin >> T >> A >> L >> R;
    // 一共有A只蚂蚁，输入每只蚂蚁的种类，然后累加到num[]里去
    for(int i = 1; i <= A; i++)
    {
        int x;
        cin >> x;
        num[x]++;
    }

    // 初始化。从家族1开始，所有蚂蚁都一样，所以不管选几只，都只有一种选法
    for(int i = 0; i <= num[1]; i++)
    {
        sum[i] = 1;
    }

    for(int i = 1; i <= T; i++)
    {
        s += num[i];
        for(int j = 0; j <= s; j++)
        {
            int x = j - num[i] - 1;
            f[j] = sum[j];
            if(x >= 0)
            {
                f[j] = (f[j] - sum[x] + mod) % mod;
            }
        }
        sum[0] = f[0];
        for(int j = 1; j <= s + num[i + 1]; j++)
        {
            sum[j] = (sum[j - 1] + f[j]) % mod;
        }
        if(i != T)
        {
            memset(f, 0, sizeof(f));
        }
    }

    int ans = 0;
    for(int i = L; i <= R; i++)
    {
        (ans += f[i]) %= mod;
    }

    cout<< ans % mod;
    return 0;
}
