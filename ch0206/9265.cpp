// 开Long long，要不最后一个点过不去

#include <cstring>
#include <iostream>
using namespace std;
long long f[100];
long long fib(long long t)
{
    if(t == 1 || t == 2)
    {
        return 1;
    }
    if(f[t] != -1)
    {
        return f[t];
    }
    
    f[t] = fib(t - 1) + fib(t - 2);
    
    return f[t];
}
int main()
{
    long long a;
    cin >> a;
    memset(f, -1, sizeof(f));
    cout << fib(a + 2)<< endl;
}