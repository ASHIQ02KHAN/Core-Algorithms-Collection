/*
===============================================================================
Algorithm Name : 0/1 Knapsack

Category       : Dynamic Programming

Technique      : Bottom-Up DP

Description:
Given weights and profits of items, maximize the total profit
without exceeding the knapsack capacity.

Each item can be chosen only once.

Time Complexity:
    O(n × W)

Space Complexity:
    O(n × W)

Applications:
    • Resource Allocation
    • Budget Planning
    • Cargo Loading
===============================================================================
*/

#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n)
{
    vector<vector<int>> dp(n + 1,
                           vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main()
{
    vector<int> weight = {1,3,4,5};
    vector<int> value  = {1,4,5,7};

    int capacity = 7;

    cout << "Maximum Profit = "
         << knapsack(capacity, weight, value, weight.size());

    return 0;
}
