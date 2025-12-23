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

bool is_palindrome(int n)
{
    // 对100-999之间的素数而言，只要看百位和各位
    
    return (n % 10 == n / 100);
}

int main()
{
    int n;
    cin >> n;

    int count = 1; //11永远是一个
    for (int i = 101; i <= n; i += 2) //100以内不会再有符合条件的
    {
        if (is_prime(i) && is_palindrome(i))
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
