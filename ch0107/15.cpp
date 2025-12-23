#include <bits/stdc++.h>
using namespace std;

string process(string s)
{
    int len = s.length();
    char c = s[0];
    string res;
    if (isdigit(c)) // Begins with a number
    {
        res += c;
    }
    else
    {
        if (islower(c)) // Begins with a small letter
        {
            c = c - 'a' + 'A';
        }
        res += c;
    }

    for (int i = 1; i < len; i++)
    {
        c = s[i];
        if (isupper(c)) // Begins with a small letter
        {
            c = tolower(c);
        }
        res += c;
    }
    return res;
}

int main()
{
    const int MAX = 101;
    int n;
    cin >> n;

    string s[MAX];
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++)
    {
        string r = process(s[i]);
        cout << r << endl;
    }

    return 0;
}
