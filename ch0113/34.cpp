#include <bits/stdc++.h>
using namespace std;

long base10(string s, int base)
{
    long res=0;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        int digit= s[i]-'0';
        if(digit>=base)
        {
            res=0;
            break;
        }
        res=res*base+digit;
    }

    return res;
}

int main()
{
    long p, q, r;
    cin>>p>>q>>r;

    string ps, qs, rs;
    ps=to_string(p);
    qs=to_string(q);
    rs=to_string(r);


    for(int base=2;base<=16;base++)
    {
        long ps10, rs10, qs10;
        ps10=base10(ps, base);
        qs10=base10(qs, base);
        rs10=base10(rs, base);

        if(ps10==0||qs10==0||rs10==0)
        {
            continue;
        }
        if(ps10*qs10==rs10)
        {
            cout<<base<<endl;
            return 0;
        }
    }

    cout<<0;

    return 0;
}