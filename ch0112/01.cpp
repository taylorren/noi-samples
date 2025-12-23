#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b, char op)
{
    int res;
    switch (op)
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    case '%':
        res = a % b;
        break;
    default:
        break;
    }

    return res;
}

int main()
{
    int a, b;
    char op;

    cin >> a >> op >> b;

    int result = calc(a, b, op);

    cout << result << endl;
    return 0;
}
