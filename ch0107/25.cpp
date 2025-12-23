#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cnt = 0, max_len = 0, min_len = 101, i_max, i_min;
    string s;
    getline(cin, s);
    s += ' ';
    int len = s.length();
    for (int i = 0; i <= len; i++)
    {
        if ((s[i] != ' ') && s[i] != ',')
        {
            cnt++;
        }
        else if (cnt > 0)
        {
            if (cnt > max_len)
            {
                max_len = cnt;
                i_max = i - cnt;
            }
            if (cnt < min_len)
            {
                min_len = cnt;
                i_min = i - cnt;
            }
            cnt = 0;
        }
    }

    for (int i = i_max; i < i_max + max_len; i++)
    {
        cout << s[i];
    }
    cout << endl;
    for (int i = i_min; i < i_min + min_len; i++)
    {
        cout<<s[i];
    }
    cout<<endl;

    return 0;
}