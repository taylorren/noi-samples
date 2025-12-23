#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int MAX=10001;
    int n;
    cin>>n;

    int numbers[MAX];
    for(int i=1;i<=n;i++)
    {
        cin>>numbers[i];
    }

    int needle;
    cin>>needle;

    int index=-1;
    for(int i=1;i<=n;i++)
    {
        if(needle==numbers[i])
        {
            index=i;
            break;
        }
    }
    cout<<index;
    
    return 0;
}
