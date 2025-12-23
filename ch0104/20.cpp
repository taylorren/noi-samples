#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c;
    cin>>a>>b>>c;

    float delta=b*b-4.0*a*c;
    
    if(delta==0.0)
    {
        printf("x1=x2=%.5f\n", -b/2/a);
    }
    else if(delta>0.0)
    {
        float s_delta=sqrt(delta);
        float x1, x2;
        x1=(-b+s_delta)/2/a;
        x2=(-b-s_delta)/2/a;
        printf("x1=%.5lf;x2=%.5lf\n", x1, x2);
    }
    else 
    {
        float s_delta=sqrt(-delta)/2/a;
        float x1;
        x1=-b/2.0/a;
        if(abs(x1)<1e-6)
        {
            x1=0;
        }
        printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n", x1, s_delta, x1, s_delta);
    }
    return 0;
}
