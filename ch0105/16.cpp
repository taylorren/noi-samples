#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        bool has_buy = false;
        double cost = 200, income = n;

        for (int i = 1; i <= 21; i++)
        {
            if (income >= cost)
            {
                cout << i << endl;
                has_buy = true;
                break;
            }

            income += n;
            cost *= (1 + k / 100.0);
        }

        if (!has_buy)
        {
            cout << ("Impossible");
        }
    }

    return 0;
}
