#include <bits/stdc++.h>
using namespace std;

string str;
int cnt = 0;

void show(int n)
{
    int self = 0, opp = 0;

    for (int i = 0; i < cnt; i++)
    {
        if (str[i] == 'W')
        {
            self++;
        }
        else if (str[i] == 'L')
        {
            opp++;
        }

        if((self>=n||opp>=n)&&abs(self-opp)>=2)
        {
            cout<<self<<":"<<opp<<endl;
            self=opp=0;
        }
    }

    cout<<self<<":"<<opp<<endl;;
}

int main()
{

    char ch;
    while (cin >> ch && ch != 'E')
    {
        if (ch == 'W' || ch == 'L')
        {
            str += ch;
            cnt++;
        }
    }

    show(11);
    cout << endl;
    show(21);
}