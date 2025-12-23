#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, x, y;
    cin>>n>>x>>y;

    if(n==0||x==0||n*x<y)
    {
        cout<<0<<endl;
    }
    else if(y%x==0)
    {
        cout<<n-y/x<<endl;
    }
    else 
    {
        cout<<n-y/x-1<<endl;
    }
    return 0;
}
