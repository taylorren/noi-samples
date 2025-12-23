#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n / 100 << endl; // 100
    n = n % 100;
    cout << n / 50 << endl; // 500
    n = n % 50;
    cout << n / 20 << endl; // 20
    n = n % 20;
    cout << n / 10 << endl; // 10
    n = n % 10;
    cout << n / 5 << endl; // 50
    n = n % 5;
    cout << n / 1 << endl; // 1
    n = n % 1;
    
    return 0;
}