#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(a==0)
    {
        return b;
    }
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

int main()
{

    int n;
    cin>>n;

    int a, b, x,y,d;
    char c;

    cin>>a>>c>>b;
    for(int i=2;i<=n;i++)
    {
        cin>>x>>c>>y;

        a=a*y+b*x;
        b=b*y;
        d=gcd(a,b);
        a=a/d;
        b=b/d;
    }
    
    if(b==1)
    {
        cout<<a<<endl;
    }
    else
    {
        cout<<a<<c<<b<<endl;
    }
    
    return 0;
}