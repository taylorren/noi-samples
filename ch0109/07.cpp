#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int numbers[110];

    int max=-1e9;
    int sum=0;

    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        numbers[i]=tmp;

        if(tmp>max)
        {
            max=tmp;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(numbers[i]!=max)
        {
            sum+=numbers[i];
        }
    }

    cout<<sum<<endl;

    return 0;
}
