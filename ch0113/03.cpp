#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    double q=1.0, res=0.0;

    cin>>s;

    for(int i=2;i<s.length();i++)
    {
        q/=8.0;
        res+=q*(s[i]-'0');
    }

    cout<<s<<" [8] = "<<setprecision(42)<<res<<" [10]";

    return 0;
}
