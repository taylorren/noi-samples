#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int total=(n-2)*180;
    for(int i=1;i<n;i++)
    {
        int a;
        cin>>a;
        total-=a;
    }

    cout<<total<<endl;
    return 0;
}
