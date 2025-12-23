#include <bits/stdc++.h>
using namespace std;

const double epsilon = 1e-9;

int main()
{
    double s = 1.5;
    double e = 2.4;

    while (s < e)
    {
        double x = (s + e) / 2;
        double tmp = x * x * x * x * x - 15 * x * x * x * x + 85 * x * x * x - 225 * x * x + 274 * x - 121;
        if (abs(tmp) <= 1e-9)
        {
            cout << fixed << setprecision(6) << x << endl;
            return 0;
        }
        if (tmp > 0)
        {
            s = x;
        }
        else
        {
            e = x;
        }
    }

    return 0;
}
