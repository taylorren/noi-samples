#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int len=s.length();

    int count=1;
    char current=s[0];
    string res;

    for(int i=1;i<len;i++)
    {
        char c=s[i];
        if(c==current)
        {
            count++;
        }
        else 
        {
            res+=to_string(count);
            res+=current;
            current=c;
            count=1;
        }
    }
    res+=to_string(count);
    res+=current;

    cout<<res<<endl;

    return 0;
}
