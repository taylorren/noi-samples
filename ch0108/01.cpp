#include <bits/stdc++.h>

using namespace std;

const int N=5;

void output(int m[N][N], int row)
{
    for (int col=0;col<N;col++)
    {
        cout<<m[row][col]<<" ";
    }
    cout<<endl;
}
int main()
{
    
    int m[N][N];
    int row, col;

    for(row=0;row<N;row++)
    {
        for(col=0;col<N;col++)
        {
            cin>>m[row][col];
        }
    }

    int r1, r2;
    cin>>r1>>r2;

    for(row=0;row<N;row++)
    {
        int actual;
        if(row==r1-1)
        {
            actual=r2-1;
        }
        else if(row==r2-1)
        {
            actual=r1-1;
        }
        else
        {
            actual=row;
        }
        output(m, actual);
    }


    return 0;
}
