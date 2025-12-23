#include <iostream>
#include <cstring>

using namespace std;

bool is_prime(int n)
{
    if(n==1)
    {
        return false;
    }
    bool prime=true;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            prime=false;
            break;
        }
    }
    return prime;
}
int main()
{
    int count=0;
    int x,y;
    cin>>x>>y;
    if(x>y)
    {
        swap(x,y);
    }

    for(int i=x;i<=y;i++)
    {
        if(is_prime(i))
        {
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}