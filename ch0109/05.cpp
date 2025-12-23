#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int max=-1, min=1e7;

    for(int i=1;i<=n;i++)
    {
        int s;
        cin>>s;

        if(s>max)
        {
            max=s;
        }
        if(s<min)
        {
            min=s;
        }
    }

    cout<<max-min<<endl;

    return 0;
}
