#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int MAX=101;
    string s;
    getline(cin, s);
    string res[MAX];
    int len =s.length();
    int count=0;

    for(int i=0;i<len;i++)
    {
        if(s[i]!=' ')
        {
            res[count]+=s[i];
        }
        else 
        {
            count++;
        }
    }

    for(int i=count;i>=0;i--)
    {
        cout<<res[i]<<' ';
    }

    return 0;
}
