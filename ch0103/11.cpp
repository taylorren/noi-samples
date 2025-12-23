#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    double a,b;
    cin>>a>>b;
    int q=int(a/b);
    double r=a-q*b;
    cout<<r;
    return 0;
}
