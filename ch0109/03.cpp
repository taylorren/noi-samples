#include <bits/stdc++.h>
using namespace std;

const int MAX=110;

int main()
{
    int day=0;
    int max=-1;

    for(int i=1;i<=7;i++)
    {
        int school, eca;
        cin>>school>>eca;

        int sum=school+eca;
        if(sum>8)
        {
            if(sum>max)
            {
                max=sum;
                day=i;
            }
        }
    }

    cout<<day<<endl;

    return 0;
}
