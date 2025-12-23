#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

// int main()
// {
//     string sentence;
//     getline(cin, sentence);

//     regex pattern(" +");
//     string res=regex_replace(sentence, pattern, " ");
//     cout<<res<<endl;
//     return 0;
// }

string a;
char b[10001];
int now;
int main()
{

    getline(cin, a);
    int l = a.length();
    int flag = 0;
    
    for (int i = 0; i <= l; i++)
    {
        if (a[i] != ' ')
        {
            b[now] = a[i];
            now++;
            flag = 0;
        } 
        else
        {
            if (flag == 1)
                a[i] = '*';
            else
            {
                flag = 1;
                b[now] = ' ';
                now++;
            }
        }
    }
    puts(b);

    return 0;
}