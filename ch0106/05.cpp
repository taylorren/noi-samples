#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int MAX=101;
    int count;
    cin>>count;
    
    int g[4]={0, 0, 0, 0};
    for(int i=1;i<=count;i++)
    {
        int tmp;
        cin>>tmp;
        
        if(tmp>=61)
        {
            g[3]++;
        }
        else if(tmp>=36)
        {
            g[2]++;
        }
        else if(tmp>=19)
        {
            g[1]++;
        }
        else{
            g[0]++;
        }
    }

    for(int i=0;i<4;i++)
    {
        printf("%.2f%%\n", 100.*g[i]/count);
    }
    
    return 0;
}
