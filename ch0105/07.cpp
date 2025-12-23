#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int gold=0, silver=0, bronze=0;
    int g, s, b;

    for (int i=1;i<=n;i++)
    {
        cin>>g>>s>>b;
        gold+=g;
        silver+=s;
        bronze+=b;
    }

    printf("%d %d %d %d\n", gold, silver, bronze, gold+silver+bronze);
    return 0;
}
