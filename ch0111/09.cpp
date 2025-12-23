#include <bits/stdc++.h>
using namespace std;

const double eps=1e-12;
const double PI=acos(-1);

int main()
{
    double l0, delta_c, coefficient;
    cin>>l0>>delta_c>>coefficient;

    double l1=(1+delta_c*coefficient)*l0;
    double l=0, r=PI, mid;
    double theta;

    if(delta_c*coefficient*l0<=eps)
    {
        cout<<"0.000"<<endl;
        return 0;
    }
    
    while(abs(l-r)>eps)
    {
        mid=(l+r)/2;
        theta=l0/2/sin(mid/2);
        double new_l=mid*theta;

        if(new_l>l1)
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }

    theta=l0/2/sin(l/2);
    double result=theta-l0/2/tan(l/2);
    cout<<fixed<<setprecision(3)<<result<<endl;

    return 0;
}
