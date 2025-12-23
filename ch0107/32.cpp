#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    int i, len, k;
    while (getline(cin, a))
    {
        len = a.length();
        for (i = 0; i < len; i++)
        {
            if (a[i] >= 'a' && a[i] <= 'z')
                a[i] = a[i] - 32; // 转为大写字母
        }
        for (i = 0; i < len; i++)
        {
            k = 0;
            while (a[i] == a[i + 1])
            {
                k++;
                i++;
            }
            printf("(%c,%d)", a[i], k + 1);
        }
        printf("\n");
    }
    return 0;
}
