class Solution {
 public:
  int numDistinct(string s, string t) {
    int m = s.size();
    int n = t.size();

    vector<vector<unsigned long long>> dp(m + 1,
                                          vector<unsigned long long>(n + 1));

    for (int i = 0; i <= m; ++i) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[m][n];
  }
};
// Runtime: 24 ms, faster than 44.90%
// Memory Usage: 18.8 MB, less than 17.04%
// 2021.9.19 at 茗筑美嘉