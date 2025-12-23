#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    float sum = 0;
    float p, q, next_p, next_q;
    p = 1.0;
    q = 2.0;

    for (int i = 1; i <= n; i++)
    {
        float temp = q / p;
        sum += temp;
        next_q = p + q;
        next_p = q;
        p = next_p;
        q = next_q;
    }
    cout << fixed << setprecision(4) << sum << endl;
    return 0;
}
