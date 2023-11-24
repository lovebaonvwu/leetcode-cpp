class Solution {
 public:
  int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    vector<vector<int>> dp(n, vector<int>(n, n));

    for (auto& m : mines) {
      dp[m[0]][m[1]] = 0;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0, k = n - 1, l = 0, r = 0, u = 0, d = 0; j < n; ++j, --k) {
        dp[i][j] = min(dp[i][j], l = dp[i][j] == 0 ? 0 : l + 1);
        dp[i][k] = min(dp[i][k], r = dp[i][k] == 0 ? 0 : r + 1);
        dp[j][i] = min(dp[j][i], u = dp[j][i] == 0 ? 0 : u + 1);
        dp[k][i] = min(dp[k][i], d = dp[k][i] == 0 ? 0 : d + 1);
      }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = max(ans, dp[i][j]);
      }
    }

    return ans;
  }
};
// 2021.9.9 at 奥盛大厦