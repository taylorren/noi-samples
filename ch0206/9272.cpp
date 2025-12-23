#include "bits/stdc++.h"

using namespace std;
const int maxN = 1e3 + 1e2;
const int MOD = 12345;
typedef long long QAQ;

int f[maxN][2];

int main()
{
    int N, X = 9;
    cin >> N;
    f[1][1] = 9;
    f[1][0] = 1;
    for(int i = 2; i <= N; ++i)
    {
        if(i == N)
        {
            X--;
        }

        f[i][1] = f[i - 1][1] * X + f[i - 1][0] * 1;
        f[i][0] = f[i - 1][0] * X + f[i - 1][1] * 1;
        f[i][1] %= MOD;
        f[i][0] %= MOD;
    }

    cout << f[N][1] << endl;
    return 0;
}