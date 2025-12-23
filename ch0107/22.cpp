#include <bits/stdc++.h>
using namespace std;

struct account
{
    string user;
    string password;
};

string convert_password(string p)
{
    int len = p.length();
    string r;
    for (int i = 0; i < len; i++)
    {
        if (isupper(p[i]))
        {
            r += tolower(p[i]);
        }
        else if (islower(p[i]))
        {
            r += toupper(p[i]);
        }
        else
        {
            r += p[i];
        }
    }

    return r;
}

int main()
{
    const int MAX = 10001;
    string email_account;
    cin >> email_account;

    int n;
    cin >> n;
    int count = 0;
    account lists[MAX];
    for (int i = 1; i <= n; i++)
    {
        string u, p, e;
        cin >> u >> p >> e;
        if (e == email_account)
        {
            lists[count].user = u;
            lists[count].password = convert_password(p);
            count++;
        }
    }
    if (count == 0)
    {
        cout << "empty" << endl;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << lists[i].user << " " << lists[i].password << endl;
        }
    }
    return 0;
}
