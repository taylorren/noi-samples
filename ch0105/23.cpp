#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int balance, n;
    cin>>balance>>n;
    int count=0;

    for(int i=1;i<=n;i++)
    {
        int consume;
        cin>>consume;
        if(balance>=consume)
        {
            balance-=consume;
        }
        else
        {
            count++;
        }
    }
    cout<<count<<endl;
}
