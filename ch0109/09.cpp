#include <bits/stdc++.h>
using namespace std;
const int MAX=10001;

int main()
{
    int counts[MAX]={0};
    int max=-1;
    
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;

        if(tmp>max)
        {
            max=tmp;
        }
        counts[tmp]++;
    }

    for(int i=0;i<=max;i++)
    {
        cout<<counts[i]<<endl;
    }

    return 0;
}
