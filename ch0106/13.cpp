#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char digits[30];
    cin>>digits;

    int count=0;
    for(int k=2;k<=9;k++)
    {
        int t=0;
        for (int i=0;i<strlen(digits);i++)
        {
            t=t*10+digits[i]-'0';
            t%=k;
        }
        if(t==0)
        {
            cout<<k<<" ";
            count++;
        }
    }
    if(count==0)
    {
        cout<<"none";
    }

    return 0;
}
