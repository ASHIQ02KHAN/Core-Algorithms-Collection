/*
===============================================================================
Algorithm Name : Fibonacci Sequence (Dynamic Programming)

Category       : Dynamic Programming

Technique      : Bottom-Up DP (Tabulation)

Description:
The Fibonacci sequence is defined as:

    F(0) = 0
    F(1) = 1
    F(n) = F(n-1) + F(n-2)

Instead of solving the same subproblems repeatedly,
Dynamic Programming stores previously computed values,
making the algorithm much faster than recursion.

Time Complexity:
    Best Case    : O(n)
    Average Case : O(n)
    Worst Case   : O(n)

Space Complexity:
    O(n)

Stable:
    Yes

Applications:
    • Dynamic Programming basics
    • Mathematical modeling
    • Interview problems
    • Optimization techniques

===============================================================================
*/

#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main()
{
    int n = 10;

    cout << "Fibonacci(" << n << ") = "
         << fibonacci(n);

    return 0;
}
