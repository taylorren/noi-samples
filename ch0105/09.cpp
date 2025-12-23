#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int sum=0;

    if(m%2==0)
    {
        m++;
    }

    for(int i=m;i<=n;i+=2)
    {
        sum+=i;
    }

    cout<<sum<<endl;
    return 0;
}
