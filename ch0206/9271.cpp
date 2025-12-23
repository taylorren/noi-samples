#include <bits/stdc++.h>

using namespace std;
int n, f[1005][5];

int main()
{
    cin >> n;

    f[1][1] = 1;
    f[1][2] = 1;
    f[1][3] = 1;
    f[1][4] = 3;

    for(int i = 2; i <= n; i++)
    {
        f[i][1] = (f[i - 1][1] + f[i - 1][3]) % 12345;
        f[i][2] = (f[i - 1][2] + f[i - 1][3]) % 12345;
        f[i][3] = (f[i - 1][1] + f[i - 1][2] + f[i - 1][3]) % 12345;
        f[i][4] = (f[i][1] + f[i][2] + f[i][3]) % 12345;
    }

    cout << f[n][4];

    return 0;
}
