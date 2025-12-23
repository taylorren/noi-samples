#include <iostream>

using namespace std;

int main()
{
    int v, n;
    cin >> v >> n;
    int items[30];
    for(int i = 0; i < n; ++i)
    {
        cin >> items[i];
    }

    bool dp[20001] = {false};
    dp[0] = true;

    for(int i = 0; i < n; ++i)
    {
        for(int j = v; j >= items[i]; --j)
        {
            if(dp[j - items[i]])
            {
                dp[j] = true;
            }
        }
    }

    for(int j = v; j >= 0; --j)
    {
        if(dp[j])
        {
            cout << v - j << endl;
            break;
        }
    }

    return 0;
}