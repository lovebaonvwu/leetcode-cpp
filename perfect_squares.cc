class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n + 1; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }

    return dp[n];
  }
};
// Runtime: 212 ms, faster than 62.78%
// Memory Usage: 9.2 MB, less than 50.63%