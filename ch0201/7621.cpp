#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 1;
    // Loop through possible number of 5角 coins (c)
    for(int c = 0; c <= n / 5; c++)
    {
        // Remaining amount after using c 5角 coins
        int remain = n - c * 5;
        // Loop through possible number of 2角 coins (b)
        for(int b = 0; b <= remain / 2; b++)
        {
            // Calculate required number of 1角 coins (a)
            int a = remain - b * 2;
            // If a is non-negative, we have a valid combination
            if(a >= 0)
            {
                // Output in required format
                cout << setw(3) << setfill('0') << count++ << setw(12)
                     << setfill(' ') << a << setw(12) << b << setw(12) << c
                     << endl;
            }
        }
    }
    return 0;
}