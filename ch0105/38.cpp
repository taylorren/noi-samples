#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int max;
    cin>>max;

    if(max==0)
    {
        cout<<0<<endl;
        return 0;
    }

    int current;
    int i;
    for(int i=max;i>0;i--)
    {
        cin>>current;
        cout<<current*i<<" ";
    }
    cout<<endl;
    return 0;
}
