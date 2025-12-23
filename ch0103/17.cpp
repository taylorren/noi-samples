#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float d(float x1, float y1, float x2, float y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    float x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    float s;

    float d1,d2,d3, p;
    d1=d(x1, y1, x2, y2);
    d2=d(x2, y2, x3, y3);
    d3=d(x3, y3, x1, y1);
    p=0.5*(d1+d2+d3);
    s=sqrt(p*(p-d1)*(p-d2)*(p-d3));

    cout<<fixed<<setprecision(2)<<s<<endl;
    
    return 0;
}

