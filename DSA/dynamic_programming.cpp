#include <iostream>
#include <vector>
using namespace std;

// Cách đệ quy thông thường (không hiệu quả)
int fibonacci_recursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Quy hoạch động với memoization
int fibonacci_memo(int n, vector<int> &memo)
{
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];

    memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo);
    return memo[n];
}

// Quy hoạch động với tabulation
int fibonacci_tabulation(int n)
{
    if (n <= 1)
        return n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n = 10;

    // Memoization
    vector<int> memo(n + 1, -1);
    cout << "Fibonacci(" << n << ") với memoization: " << fibonacci_memo(n, memo) << endl;

    // Tabulation
    cout << "Fibonacci(" << n << ") với tabulation: " << fibonacci_tabulation(n) << endl;

    return 0;
}