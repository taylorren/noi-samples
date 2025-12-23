#include <bits/stdc++.h>
using namespace std;

double l=0, r=0;
double sz[10010];

const double PI=3.141592653589793238;


int main()
{
    int N, F;
    cin>>N>>F;
    F++;

    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        sz[i]=PI*temp*temp;
        if(sz[i]>r)
        {
            r=sz[i];
        }
    }

    while(r-l>1e-6)
    {
        double mid=(r+l)/2.0;
        int num=0;
        for(int i=0;i<N;i++)
        {
            num+=sz[i]/mid;
        }
        if(num>=F)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }

    cout<<fixed<<setprecision(3)<<l<<endl;
}
