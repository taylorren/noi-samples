#include <bits/stdc++.h>
using namespace std;

string to_upper(string s)
{
    string tmp="";
    for(auto&c: s)
    {
        if(c>='a'&&c<='z')
        {
            c=c-'a'+'A';
            tmp+=c;
        }
        else 
        {
            tmp+=c;
        }
    }

    return tmp;
}

long long convert_to_base10(string s, int base)
{
    int len=s.length();
    long long res=0;
    int digit;
    for(int i=len-1;i>=0;i--)
    {
        char c=s[i];
        if(c>='0'&&c<='9')
        {
            digit=c-'0';
        }
        else 
        {
            digit=c-'A'+10;
        }

        long tmp=digit*pow(base, len-i-1);
        res+=tmp;
    }

    return res;
}

string convert_to_base(long long l, int base)
{
    if(l==0)
    {
        return "0";
    }
    
    string res="";
    while(l>0)
    {
        int digit=l%base;
        l/=base;
        if(digit>=0&&digit<=9)
        {
            res=to_string(digit)+res;
        }
        else 
        {
            char c=digit-10+'A';
            res=c+res;
        }
    }
    return res;
}

int main()
{
    int base1,base2;
    string number;

    cin>>base1>>number>>base2;
    number=to_upper(number);
    long long dec_presentation=convert_to_base10(number, base1);
    string res=convert_to_base(dec_presentation, base2);
    cout<<res<<endl;

    return 0;
}
