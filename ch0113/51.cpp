#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int t1[150],t2[150];
int len,i;
  
int main()
{
    cin>>s1>>s2;
    len=s1.size();
    for(i=0;i<len;i++)
    {
        t1[s1[i]]++;
        t2[s2[i]]++;
    }
    sort(t1+'A',t1+'Z'+1);//这里的参数注意一下 
    sort(t2+'A',t2+'Z'+1);//不理解问度娘sort的工作原理 
    for(i='A';i<='Z';i++)
    {
        if(t1[i]!=t2[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;    
}
