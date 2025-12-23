#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int MAX=101;
    int p[MAX];
    int count;
    cin>>count;

    for(int i=1;i<=count;i++)
    {
        cin>>p[i];
    }

    for(int i=count;i>=1;i--)
    {
        cout<<p[i]<<" ";
    }

    return 0;
}
