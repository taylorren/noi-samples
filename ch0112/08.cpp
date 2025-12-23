#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int maxn = 1e6 + 5;
    int lk, lc;
    char k[105], c[1005];
    scanf("%s %s", k, c);
    lk = strlen(k);
    lc = strlen(c);
    for (int i = 0; i < lk; i++) // k to all lowwer
    {
        if (k[i] >= 'A' && k[i] <= 'Z')
            k[i] = k[i] - 'A' + 'a';
    }
    for (int i = 0; i < lc; i++)
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
            c[i] = 'A' + (c[i] - 'A' - k[i % lk] + 'a' + 26) % 26;
        else
            c[i] = 'a' + (c[i] - 'a' - k[i % lk] + 'a' + 26) % 26;
    }
    printf("%s\n", c);
    return 0;
}
//这个随便抄了一个