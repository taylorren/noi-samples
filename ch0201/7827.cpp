#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if(n < 2)
    {
        return false;
    }
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int s;
    cin >> s;
    
    int maxProduct = 0;
    // 从中间开始往两边找，这样第一次找到的质数对的积就是最大的
    int mid = s / 2;
    
    for(int i = mid; i >= 2; i--)
    {
        int j = s - i;
        if(isPrime(i) && isPrime(j))
        {
            maxProduct = i * j;
            break;
        }
    }
    
    cout << maxProduct << endl;
    return 0;
}