class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (auto& s : strs) {
      int zeros = 0, ones = 0;

      for (auto c : s) {
        if (c == '0') {
          ++zeros;
        } else {
          ++ones;
        }
      }

      auto tmp = dp;
      for (int i = zeros; i <= m; ++i) {
        for (int j = ones; j <= n; ++j) {
          dp[i][j] = max(tmp[i][j], tmp[i - zeros][j - ones] + 1);
        }
      }
    }

    return dp[m][n];
  }
};
// Runtime: 272 ms, faster than 43.02%
// Memory Usage: 101.4 MB, less than 24.69%

class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (auto& s : strs) {
      int zeros = 0, ones = 0;

      for (auto c : s) {
        if (c == '0') {
          ++zeros;
        } else {
          ++ones;
        }
      }

      for (int i = m; i >= zeros; --i) {
        for (int j = n; j >= ones; --j) {
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
      }
    }

    return dp[m][n];
  }
};
// Runtime: 196 ms, faster than 72.63%
// Memory Usage: 9.7 MB, less than 81.75%