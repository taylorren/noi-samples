#include <iostream>

using namespace std;

int main()
{
    int c,m;
    cin>>c>>m;

    bool one=(c<60)^(m<60);

    if(one)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }

    return 0;
}
