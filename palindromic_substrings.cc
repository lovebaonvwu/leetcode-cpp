class Solution {
  bool isPalindromic(const string& s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }

    return true;
  }

 public:
  int countSubstrings(string s) {
    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
      for (int j = i; j < s.size(); ++j) {
        if (isPalindromic(s, i, j)) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 152 ms, faster than 16.04%
// Memory Usage: 6.2 MB, less than 97.25%

class Solution {
 public:
  int countSubstrings(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));

    for (int i = 0; i < s.size(); ++i) {
      dp[i][i] = true;
    }

    for (int i = s.size() - 1; i >= 0; --i) {
      for (int j = i + 1; j < s.size(); ++j) {
        if (j - i == 1) {
          if (s[i] == s[j]) {
            dp[i][j] = true;
          }
        } else if (j - i > 1) {
          if (s[i] == s[j] && dp[i + 1][j - 1]) {
            dp[i][j] = true;
          }
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < s.size(); ++j) {
        if (dp[i][j]) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 36.22%
// Memory Usage: 7.6 MB, less than 60.40%

class Solution {
 public:
  int countSubstrings(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));

    for (int i = 0; i < s.size(); ++i) {
      dp[i][i] = true;
    }

    int ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      for (int j = i; j < s.size(); ++j) {
        if (j - i == 1) {
          if (s[i] == s[j]) {
            dp[i][j] = true;
          }
        } else if (j - i > 1) {
          if (s[i] == s[j] && dp[i + 1][j - 1]) {
            dp[i][j] = true;
          }
        }

        if (dp[i][j]) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 48.03%
// Memory Usage: 7.6 MB, less than 55.97%