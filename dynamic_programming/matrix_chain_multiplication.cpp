/*
===============================================================================
Algorithm Name : Matrix Chain Multiplication

Category       : Dynamic Programming

Technique      : Bottom-Up DP

Description:
Find the minimum number of scalar multiplications
needed to multiply a chain of matrices.

Time Complexity:
    O(n³)

Space Complexity:
    O(n²)

Applications:
    • Compiler Optimization
    • Scientific Computing
===============================================================================
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChain(vector<int>& p)
{
    int n = p.size();

    vector<vector<int>> dp(n,
                           vector<int>(n, 0));

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(
                    dp[i][j],
                    dp[i][k] +
                    dp[k + 1][j] +
                    p[i - 1] * p[k] * p[j]
                );
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    vector<int> dimensions = {40,20,30,10,30};

    cout << "Minimum Multiplications = "
         << matrixChain(dimensions);

    return 0;
}
