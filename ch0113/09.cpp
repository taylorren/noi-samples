#include <iostream>
#include <cstring>
#define N 410
using namespace std;

int main()
{
    string a, b;
    int as[N]={0}, bs[N]={0}, cs[N]={0}, len;
    
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
    {
        as[i] = a[a.size() - i - 1] - '0';
    }

    for (int i = 0; i < b.size(); i++)
    {
        bs[i] = b[b.size() - i - 1] - '0';
    }

    len = a.size() + b.size();

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            cs[i + j] += as[i] * bs[j];
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (cs[i] > 9)
        {
            cs[i + 1] += cs[i] / 10;
            cs[i] %= 10;
            if (i == len - 1)
            {
                len++;
            }
        }
    }

    while (len && cs[len] == 0)
    {
        len--;
    }

    for (int i = len; i >= 0; i--)
    {
        cout << cs[i];
    }
    cout << endl;
}

// https://www.cnblogs.com/jzxnl/p/11031347.html