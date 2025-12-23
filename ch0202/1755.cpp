#include <iostream>

using namespace std;

int fib[21] = {0, 1, 1}; // 第0项不用，从第1项开始

void init_fibonacci()
{
    for(int i = 3; i <= 20; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main()
{
    init_fibonacci(); // 先把所有结果算好
    
    int n;
    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;
        cout << fib[a] << endl;
    }
    return 0;
}