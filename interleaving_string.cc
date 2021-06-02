class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size();

    if (m + n != s3.size()) {
      return false;
    }

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

    dp[0][0] = true;

    for (int i = 1; i < m + 1; ++i) {
      dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    }

    for (int j = 1; j < n + 1; ++j) {
      dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
    }

    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        if ((s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j]) {
          dp[i][j] = true;
        } else if ((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1]) {
          dp[i][j] = true;
        }
      }
    }

    return dp[m][n];
  }
};
// Runtime: 4 ms, faster than 65.75%
// Memory Usage: 6.6 MB, less than 61.07%