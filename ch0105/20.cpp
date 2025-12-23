#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double h0, i, s, h;
    cin >> h0;

    s = 0;
    h = 0;
    for (int i = 1; i <= 10; i++)
    {
        s += h0 + h;
        h = h0 * 0.5;
        h0 = h;
    }

    cout << s << endl
         << h << endl;
    return 0;
}
