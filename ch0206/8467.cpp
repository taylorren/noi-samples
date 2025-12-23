#include <iostream>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

int m, n;
int d[15][15];

int main()
{
    // freopen("D:\\txt.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> m >> n;
        memset(d, 0, sizeof(d));
        d[0][0] = 1;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= i; j++)
            {
                d[i][j] = d[i - j][j] + d[i - 1][j - 1];
            }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans += d[m][i];
        cout << ans << endl;
    }
    return 0;
}