#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    bool is = true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            is = false;
            break;
        }
    }
    return is;
}

int main()
{
    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; i++)
    {
        if (is_prime(i))
        {
            if (i == n)
            {
                cout << i << endl;
            }
            else
            {
                cout << i << ",";
            }
            continue;
        }
        else
        {
            for (int j = i - 1; j >= 2; j--)
            {
                if (is_prime(j) && i % j == 0)
                {
                    if (i == n)
                    {
                        cout << j << endl;
                    }
                    else
                    {
                        cout << j << ",";
                    }
                    break;
                }
            }
        }
    }

    return 0;
}
