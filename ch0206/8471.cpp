#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string& s, int start, int end)
{
    while(start < end)
    {
        if(s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int minCut(string s)
{
    int n = s.size();
    if(n == 0)
        return 0;

    vector<int> dp(n);
    for(int i = 0; i < n; i++)
    {
        if(isPalindrome(s, 0, i))
        {
            dp[i] = 0; // No cut needed if the whole substring is a palindrome
        }
        else
        {
            dp[i] = i; // Maximum cuts possible
            for(int j = 0; j < i; j++)
            {
                if(isPalindrome(s, j + 1, i))
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    return dp[n - 1];
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        cout << minCut(s) << endl;
    }
    return 0;
}