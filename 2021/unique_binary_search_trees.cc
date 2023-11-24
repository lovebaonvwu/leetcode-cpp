class Solution {
 public:
  int numTrees(int n) {
    if (n == 1) {
      return 1;
    }

    if (n == 2) {
      return 2;
    }

    vector<int> dp(n + 1);

    dp[1] = dp[0] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[i - 1 - j] * dp[j];
      }
    }

    return dp[n];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 14.09%

class Solution {
 public:
  int numTrees(int n) {
    vector<int> dp(n + 1);

    dp[1] = dp[0] = 1;

    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[i - 1 - j] * dp[j];
      }
    }

    return dp[n];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 6.32%