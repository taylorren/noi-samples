#include <iostream>
#include <iomanip>
using namespace std;

bool contains(int i, int digit)
{
    while(i>0)
    {
        if(i%10==digit)
        {
            return true;
        }
        else
        {
            i/=10;
        }

    }
    return false;
}

int main()
{
    int max;
    cin>>max;
    int sum=0;
    for (int i=1;i<=max;i++)
    {
        if(i%7!=0&&!contains(i, 7))
        {
            sum+=i*i;
        }
    }
    cout<<sum<<endl;
    return 0;
}
