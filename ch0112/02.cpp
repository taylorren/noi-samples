#include <bits/stdc++.h>
using namespace std;

float calc(int sms)
{
    float cost = 0.1;
    while (sms > 70)
    {
        cost += 0.1;
        sms -= 70;
    }

    return cost;
}

int main()
{
    int n;
    cin >> n;

    float sum = 0;

    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        sum += calc(tmp);
    }

    cout << fixed << setprecision(1) << sum << endl;

    return 0;
}
