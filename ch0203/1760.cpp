#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 预处理斐波那契数列模1000的周期
    vector<int> fib(3000);
    fib[1] = fib[2] = 1;
    int period = 0;
    
    // 寻找周期
    for(int i = 3; i <= 2500; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
        if(fib[i] == 1 && fib[i - 1] == 1)
        {
            period = i - 2;
            break;
        }
    }
    
    int n;
    cin >> n;
    
    while(n--)
    {
        int a;
        cin >> a;
        if(period)
        {
            a = (a - 1) % period + 1;
        }
        cout << fib[a] << '\n';
    }
    
    return 0;
}