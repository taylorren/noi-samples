#include <bits/stdc++.h>
using namespace std;

void count_appearances(string s, int a[26])
{
    int len=s.length();
    for(int i=0;i<len;i++)    
    {
        a[s[i]-'a']++;
    }

}

int find_diff(int count[26])
{
    int min=1000, max=-1000;
    for(int i=0;i<26;i++)
    {
        int c=count[i];
        if(c==0)
        {
            continue;
        }
        if(c>max)
        {
            max=c;
        }
        if(c<min)
        {
            min=c;
        }
    }
    return max-min;
}

bool is_prime(int n)
{
    bool prime=true;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            prime=false;
            return prime;
        }
    }
    return prime;
}

int main()
{
    string s;
    cin>>s;

    int appearances[26]={0};
    count_appearances(s, appearances);

    int diff=find_diff(appearances);
    if(diff==0||diff==1||!is_prime(diff))
    {
        cout<<"No Answer"<<endl<<0<<endl;
    }
    else 
    {
        cout<<"Lucky Word"<<endl<<diff<<endl;
    }

    return 0;
}
