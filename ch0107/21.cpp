#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s[200], orig, repl;
    int i=0, k=0;

    char a=' ';
    while(a==' ')
    {
        cin>>s[i];
        a=getchar();
        i++;
        k++;
    }

    cin>>orig>>repl;

    for(int j=0;j<k;j++)
    {
        if(s[j]==orig)
        {
            s[j]=repl;
        }
    }

    for(int j=0;j<k;j++)
    {
        cout<<s[j]<<" ";
    }

    return 0;
}
