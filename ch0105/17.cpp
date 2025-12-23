#include <iostream>

using namespace std;

int main()
{
    int k;
    cin>>k;
    int a1=1, a2=1;
    int a3;
    if(k==1||k==2)
    {
        cout<<1<<endl;
        return 0;
    }

    for(int i=3;i<=k;i++)
    {
        a3=a1+a2;
        a1=a2;
        a2=a3;
    }
    cout<<a3<<endl;
}
