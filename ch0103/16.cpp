#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;

    double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    cout<<fixed<<setprecision(3)<<d<<endl;
    
    return 0;
}
