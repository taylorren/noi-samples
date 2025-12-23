#include <iostream>

using namespace std;

int main()
{
    int k;
    cin>>k;

    int ones=0, fives=0, tens=0;
    int v;
    for(int i=1;i<=k;i++)
    {
        cin>>v;

        if(v==1)
        {
            ones++;
        }
        if(v==5)
        {
            fives++;
        }
        if(v==10)
        {
            tens++;
        }
    }

    cout<<ones<<endl<<fives<<endl<<tens<<endl;
    return 0;
}
