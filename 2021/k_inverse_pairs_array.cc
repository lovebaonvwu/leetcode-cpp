class Solution {
 public:
  int kInversePairs(int n, int k) {
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 0; i < dp.size(); ++i) {
      dp[i][0] = 1;
    }

    for (int i = 1; i < dp.size(); ++i) {
      int sum = dp[i - 1][0];
      for (int j = 1; j <= k; ++j) {
        if (j >= i) {
          sum -= dp[i - 1][j - i];
        }

        if (sum < 0) {
          sum += mod;
        }

        sum += dp[i - 1][j];
        sum %= mod;

        dp[i][j] = sum;
      }
    }

    return dp[n][k];
  }
};
// Runtime: 24 ms, faster than 74.87%
// Memory Usage: 16.4 MB, less than 24.06%