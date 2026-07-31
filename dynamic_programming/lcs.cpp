/*
===============================================================================
Algorithm Name : Longest Common Subsequence (LCS)

Category       : Dynamic Programming

Technique      : Bottom-Up DP (2D Table)

Description:
Given two strings, find the length of the longest subsequence
present in both strings.

Example:

String 1 : AGGTAB
String 2 : GXTXAYB

LCS = GTAB
Length = 4

Time Complexity:
    O(m × n)

Space Complexity:
    O(m × n)

Applications:
    • DNA Sequence Matching
    • Version Control (Git Diff)
    • Text Comparison
    • Bioinformatics
===============================================================================
*/

#include <iostream>
#include <vector>

using namespace std;

int LCS(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << "Length of LCS = "
         << LCS(X, Y);

    return 0;
}
