class Solution {
 public:
  int valueAfterKSeconds(int n, int k) {
    vector<vector<long long>> dp(k + 1, vector<long long>(n));
    for (int j = 0; j < n; ++j) {
      dp[0][j] = 1;
    }

    for (int i = 0; i <= k; ++i) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= k; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
      }
    }

    return dp[k][n - 1];
  }
};
// 300 ms
// 624.36 MB