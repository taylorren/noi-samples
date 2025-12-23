#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;

    int flag = 1;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == s[i + 1])
        {
            flag++;
        }
        else
        {
            if (flag >= k)
            {
                cout << s[i] << endl;
                return 0;
            }
            flag = 1;
        }
    }
    cout << "No" << endl;
    return 0;
}