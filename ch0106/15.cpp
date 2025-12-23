#include <iostream>

using namespace std;

const int MAX=101;
int f[MAX]={0};
int sum[MAX]={0};

void fact(int x)
{
    int carry=0;
    for(int i=MAX-1;i>=0;i--)
    {
        f[i]=f[i]*x+carry;
        carry=f[i]/10;
        f[i]%=10;
    }
}

void add()
{
    int carry=0;
    for(int i=MAX-1;i>=0;i--)
    {
        sum[i]+=f[i]+carry;
        carry=sum[i]/10;
        sum[i]%=10;
    }
}

void output()
{
    int s=0;
    for(int i=0;i<=MAX;i++)
    {
        if(sum[i]!=0)
        {
            s=i;
            break;
        }
    }

    for(int i=s;i<=MAX-1;i++)
    {
        cout<<sum[i];
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    f[MAX-1]=1;
    sum[MAX-1]=1;
    for(int i=2;i<=n;i++)
    {
        fact(i);
        add();
    }
    output();
    return 0;
}
