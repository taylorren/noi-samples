#include <iostream>
#include <string>

bool isMatch(const std::string& pattern, const std::string& str)
{
    int m = pattern.size();
    int n = str.size();
    bool dp[21][21] = {false};

    dp[0][0] = true;

    for(int i = 1; i <= m; ++i)
    {
        if(pattern[i - 1] == '*')
        {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(pattern[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main()
{
    std::string pattern, str;
    std::getline(std::cin, pattern);
    std::getline(std::cin, str);

    if(isMatch(pattern, str))
    {
        std::cout << "matched" << std::endl;
    }
    else
    {
        std::cout << "not matched" << std::endl;
    }

    return 0;
}