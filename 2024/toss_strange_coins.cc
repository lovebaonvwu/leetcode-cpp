class Solution {
 public:
  double probabilityOfHeads(vector<double>& prob, int target) {
    int n = prob.size();
    vector<vector<double>> dp(n + 1, vector<double>(target + 2));
    dp[1][1] = prob[0];
    dp[1][0] = 1 - prob[0];

    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j <= target; ++j) {
        dp[i][j] = dp[i - 1][j] * (1 - prob[i - 1]);
        if (j > 0) {
          dp[i][j] += dp[i - 1][j - 1] * prob[i - 1];
        }
      }
    }

    return dp[n][target];
  }
};
// 31 ms
// 57.53 MB
