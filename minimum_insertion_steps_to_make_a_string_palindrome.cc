class Solution {
 public:
  int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    string t = s;
    reverse(t.begin(), t.end());

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[i] == t[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
      }
    }

    return n - dp[n][n];
  }
};
// Runtime 113 ms
// Memory 28.5 MB