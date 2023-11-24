class Solution {
 public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();

    if (n < d) {
      return -1;
    }

    vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
      for (int k = 1; k <= d; ++k) {
        int md = 0;
        for (int j = i - 1; j >= k - 1; --j) {
          md = max(md, jobDifficulty[j]);
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + md);
        }
      }
    }

    return dp[n][d];
  }
};
// Runtime: 68 ms, faster than 62.53%
// Memory Usage: 8 MB, less than 30.04%
// 2022.10.16 at 奥盛大厦