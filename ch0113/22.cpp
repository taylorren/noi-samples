#include <bits/stdc++.h>
using namespace std;


int main()
{
    const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    const int len=sizeof(primes)/sizeof(int);
    int counts[len]={};

    int n;
    ostringstream str;

    cin>>n;
    for(int i=0;i<len;i++)
    {
        while(n%primes[i]==0)
        {
            n=n/primes[i];
            counts[i]++;
        }
        if(n<=1)
        {
            break;
        }
    }
    for(int i=0;i<len;i++)
    {
        if(counts[i]!=0)
        {
            str<<primes[i];
            if(counts[i]>1)
            {
                str<<"^"<<counts[i]<<"*";
            }
            else
            {
                str<<"*";
            }
        }
    }

    string res=str.str();
    res.pop_back();
    cout<<res;
}