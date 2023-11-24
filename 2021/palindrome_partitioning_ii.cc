class Solution {
 public:
  int minCut(string s) {
    int n = s.size();

    vector<vector<int>> valid(n, vector<int>(n, 1));

    for (int l = 2; l <= n; ++l) {
      for (int i = 0, j = i + l - 1; j < n; ++i, ++j) {
        valid[i][j] = s[i] == s[j] && valid[i + 1][j - 1];
      }
    }

    vector<int> dp(n, n);

    for (int i = 0; i < n; ++i) {
      if (valid[0][i]) {
        dp[i] = 0;
        continue;
      }

      for (int j = 0; j < i; ++j) {
        if (valid[j + 1][i]) {
          dp[i] = min(dp[i], dp[j] + 1);
        }
      }
    }

    return dp[n - 1];
  }
};
// Runtime: 84 ms, faster than 45.43%
// Memory Usage: 37.1 MB, less than 24.84%
// 2021.8.7 at 茗筑美嘉