class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1));

    for (int i = s.size(); i >= 1; --i) {
      for (int j = i; j <= s.size(); ++j) {
        if (i == j) {
          dp[i][j] = 1;
        } else if (s[i - 1] == s[j - 1] && i + 1 == j) {
          dp[i][j] = 2;
        } else if (s[i - 1] == s[j - 1]) {
          dp[i][j] = 2 + dp[i + 1][j - 1];
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[1][s.size()];
  }
};
// Runtime: 68 ms, faster than 65.01%
// Memory Usage: 69.3 MB, less than 90.00%

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1));

    for (int i = s.size(); i >= 1; --i) {
      for (int j = i; j <= s.size(); ++j) {
        if (i == j) {
          dp[i][j] = 1;
        } else if (s[i - 1] == s[j - 1]) {
          dp[i][j] = 2 + dp[i + 1][j - 1];
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[1][s.size()];
  }
};
// Runtime: 76 ms, faster than 51.15%
// Memory Usage: 69.4 MB, less than 50.00%

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    if (s.empty()) {
      return 0;
    }

    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1));
    return lps(s, 0, s.size() - 1, dp);
  }

  int lps(string& s, int begin, int end, vector<vector<int>>& dp) {
    if (dp[begin][end] > 0) {
      return dp[begin][end];
    }

    int ans = 0;
    if (begin == end) {
      ans = 1;
    } else if (s[begin] == s[end]) {
      if (begin + 1 == end) {
        ans = 2;
      } else {
        ans = 2 + lps(s, begin + 1, end - 1, dp);
      }
    } else {
      ans = max(lps(s, begin + 1, end, dp), lps(s, begin, end - 1, dp));
    }

    dp[begin][end] = ans;

    return ans;
  }
};
// Runtime: 72 ms, faster than 57.14%
// Memory Usage: 69.7 MB, less than 10.00%