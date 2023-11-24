class Solution {
  bool isPalindrome(const string& s, int i, int j) {
    if (i > j) {
      return false;
    }

    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }

    return true;
  }

 public:
  bool checkPartitioning(string s) {
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i + 1; j < s.size(); ++j) {
        if (isPalindrome(s, 0, i) && isPalindrome(s, i + 1, j) &&
            isPalindrome(s, j + 1, s.size() - 1)) {
          return true;
        }
      }
    }

    return false;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  bool checkPartitioning(string s) {
    int n = s.size();

    vector<vector<bool>> dp(n, vector<bool>(n));

    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
    }

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j] && (j - 1 == i || dp[i + 1][j - 1])) {
          dp[i][j] = true;
        }
      }
    }

    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        if (dp[0][i] && dp[i + 1][j] && dp[j + 1][n - 1]) {
          return true;
        }
      }
    }

    return false;
  }
};
// Runtime: 236 ms, faster than 61.38%
// Memory Usage: 17.3 MB, less than 54.06%