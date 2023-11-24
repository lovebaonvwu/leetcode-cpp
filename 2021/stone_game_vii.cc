class Solution {
 public:
  int stoneGameVII(vector<int>& stones) {
    int n = stones.size();

    vector<int> presum(n + 1);

    for (int i = 1; i < n + 1; ++i) {
      presum[i] = presum[i - 1] + stones[i - 1];
    }

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 2; i <= n; ++i) {
      for (int l = 0, r = l + i - 1; r < n; ++l, ++r) {
        dp[l][r] = max(presum[r + 1] - presum[l + 1] - dp[l + 1][r],
                       presum[r] - presum[l] - dp[l][r - 1]);
      }
    }

    return dp[0][n - 1];
  }
};
// Runtime: 288 ms, faster than 36.08%
// Memory Usage: 84.5 MB, less than 26.90%