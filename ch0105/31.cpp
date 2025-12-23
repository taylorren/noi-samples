#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    const int max=5555;
    short lamps[max];
    int n,m;
    cin>>n>>m;
    int first=1;
    memset(lamps, 1, sizeof(lamps));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j%i==0)
            {
                lamps[j]=!lamps[j];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!lamps[i])
        {
            if(first)
            {
                first=0;
            }
            else
            {
                cout<<",";
            }
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
