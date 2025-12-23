#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case
    std::vector<int> prices = {10, 20, 50, 100};

    for(int price : prices)
    {
        for(int i = price; i <= n; ++i)
        {
            dp[i] += dp[i - price];
        }
    }

    std::cout << dp[n] << std::endl;
    return 0;
}