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

class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, -1);
    function<int(int)> dfs = [&](int n) -> int {
      if (n == 0)
        return 0;
      if (n == 1)
        return 1;

      if (dp[n] != -1)
        return dp[n];

      int ret = INT_MAX;
      for (int i = 1; i * i <= n; ++i) {
        ret = min(ret, dfs(n - i * i) + 1);
      }

      return dp[n] = ret;
    };

    return dfs(n);
  }
};
// 276ms
// 13.33MB