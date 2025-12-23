#include <bits/stdc++.h>
using namespace std;

double evaluate()
{
    char token[20];
    scanf("%s", token);

    // 如果是运算符，则递归计算其操作数
    if(strcmp(token, "+") == 0)
    {
        double a = evaluate();
        double b = evaluate();
        return a + b;
    }
    else if(strcmp(token, "-") == 0)
    {
        double a = evaluate();
        double b = evaluate();
        return a - b;
    }
    else if(strcmp(token, "*") == 0)
    {
        double a = evaluate();
        double b = evaluate();
        return a * b;
    }
    else if(strcmp(token, "/") == 0)
    {
        double a = evaluate();
        double b = evaluate();
        return a / b;
    }
    else
    {
        // 如果是操作数，则直接返回其值
        return atof(token);
    }
}

int main()
{
    double result = evaluate();
    cout << fixed<<setprecision(6)<<result;
    return 0;
}