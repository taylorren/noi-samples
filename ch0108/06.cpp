#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
short a[MAX][MAX];
short b[MAX][MAX];

int main()
{

    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>a[i][j];
        }
    }    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>b[i][j];
        }
    }    
    
    int total=m*n; // total points
    int count=0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i][j]==b[i][j])
            {
                count++;
            }
        }
    }

    cout<<fixed<<setprecision(2)<<100.*count/total<<endl;

    return 0;
}
