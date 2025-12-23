#include <iostream>

using namespace std;

int main()
{
    int n, max;
    cin>>n;
    int i,j;

    for(i =2;i*i<n;i++)
    {
        if(n%i==0)
        {
            j=n/i;
            break;
        }
    }
    if(i>j)
    {
        max=i;
    }
    else 
    {
        max=j;
    }

    cout<<max<<endl;

    return 0;
}
