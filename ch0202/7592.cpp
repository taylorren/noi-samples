#include <iostream>
using namespace std;

// 递归实现辗转相除法求最大公约数
int gcd(int a, int b)
{
    if(a%b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}