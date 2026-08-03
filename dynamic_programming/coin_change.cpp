/*
===============================================================================
Algorithm Name : Coin Change Problem

Category       : Dynamic Programming

Technique      : Bottom-Up DP

Description:
Find the minimum number of coins required
to make a target amount.

Coins may be used unlimited times.

Time Complexity:
    O(n × Amount)

Space Complexity:
    O(Amount)

Applications:
    • Financial Systems
    • ATM Software
    • Currency Optimization
===============================================================================
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i],
                            dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX)
        return -1;

    return dp[amount];
}

int main()
{
    vector<int> coins = {1,2,5};

    int amount = 11;

    cout << "Minimum Coins Required = "
         << coinChange(coins, amount);

    return 0;
}
