#include<iostream> 
#include<vector>
using namespace std;

int main()
{
    int a,n;
    while(cin>>a>>n)
    {
        // 使用vector替代变长数组
        vector<int> b(n+1);
        b[1]=a;
        int p2=1;int t2=a*2+1;
        int p3=1;int t3=a+t2;
        
        for(int i=2; i<=n; i++)
        {
            if(t2==t3)
            {
                b[i]=t2;
                t2=b[++p2]*2+1;
                t3=b[++p3]*3+1;
            }
            else if(t2<t3)
            {
                b[i]=t2;
                t2=b[++p2]*2+1;
            }
            else
            {
                b[i]=t3;
                t3=b[++p3]*3+1;
            }
        }
        cout<<b[n]<<endl;
    }
    return 0;
}
