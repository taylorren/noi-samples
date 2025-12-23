#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int x,y,z;
    int xyz, zyx;

    for(x=1;x<7;x++)
    {
        for(y=0;y<7;y++){
            for(z=1;z<7;z++)
            {
                xyz=x*49+y*7+z;
                zyx=z*81+y*9+x;
                if(xyz==zyx)
                {
                    printf("%d\n%d%d%d\n%d%d%d\n", xyz, x,y,z,z,y,x);
                }
            }
        }
    }

    return 0;
}
