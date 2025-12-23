#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, s1, s2;
    while(cin>>s>>s1)
    {
        s+=s;
        s1+=s1;
        int f=0;

        for(int j=s.size()/2;j>=1;j--)
        {
            for(int i=0;i<s.size()/2;i++)
            {
                s2=s.substr(i,j);
                if(s1.find(s2)!=string::npos)
                {
                    cout<<j<<endl;
                    f=1;
                    break;
                }
            }
            if(f==1)
            {
                break;
            }
        }

        if(f==0)
        {
            cout<<0<<endl;
        }    
    }
    return 0;
}
