#include<bits/stdc++.h>
using namespace std;
int main() {
    int a_count = 0, b_count = 0;
    for (int i = 1;i <= 1000;i++)
    {
        int ones = 0, zeros = 0;
        int d = i;
        while (d > 0)
        {
            int r = d % 2;
            if (r == 1)
            {
                ones++;
            }
            else
            {
                zeros++;
            }
            d /= 2;
        }
        if (ones > zeros)
        {
            a_count++;
        }
        else
        {
            b_count++;
        }
    }

    cout << a_count << " " << b_count;
}