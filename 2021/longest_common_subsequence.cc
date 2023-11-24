class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));

    for (int i = 0; i < dp[0].size(); ++i) {
      dp[0][i] = 0;
    }

    for (int i = 0; i < dp.size(); ++i) {
      dp[i][0] = 0;
    }

    for (int i = 1; i < dp.size(); ++i) {
      for (int j = 1; j < dp[i].size(); ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[text1.size()][text2.size()];
  }
};
// Runtime: 12 ms, faster than 88.66%
// Memory Usage: 14.8 MB, less than 100.00%

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
    return lcs(text1, text2, text1.size(), text2.size(), dp);
  }

  int lcs(string& s1, string& s2, int len1, int len2, vector<vector<int>>& dp) {
    int ans = 0;

    if (dp[len1][len2] > -1) {
      ans = dp[len1][len2];
    } else if (len1 == 0 || len2 == 0) {
      ans = 0;
    } else if (s1[len1 - 1] == s2[len2 - 1]) {
      dp[len1][len2] = 1 + lcs(s1, s2, len1 - 1, len2 - 1, dp);
      ans = dp[len1][len2];
    } else {
      dp[len1][len2] =
          max(lcs(s1, s2, len1, len2 - 1, dp), lcs(s1, s2, len1 - 1, len2, dp));
      ans = dp[len1][len2];
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 8.25%
// Memory Usage: 15.6 MB, less than 100.00%

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));
    return lcs(text1, text2, 0, 0, dp);
  }

  int lcs(string& s1,
          string& s2,
          int begin1,
          int begin2,
          vector<vector<int>>& dp) {
    if (begin1 == s1.size() || begin2 == s2.size()) {
      return 0;
    }

    if (dp[begin1][begin2] > 0) {
      return dp[begin1][begin2];
    }

    int ans = 0;

    if (s1[begin1] == s2[begin2]) {
      ans = 1 + lcs(s1, s2, begin1 + 1, begin2 + 1, dp);
    } else {
      ans = max(lcs(s1, s2, begin1, begin2 + 1, dp),
                lcs(s1, s2, begin1 + 1, begin2, dp));
    }

    dp[begin1][begin2] = ans;

    return ans;
  }
};
// Runtime: 68 ms, faster than 5.18%
// Memory Usage: 15.6 MB, less than 100.00%

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));
    return lcs(text1, text2, text1.size(), text2.size(), dp);
  }

  int lcs(string& s1, string& s2, int len1, int len2, vector<vector<int>>& dp) {
    int ans = 0;

    if (dp[len1][len2] > 0) {
      ans = dp[len1][len2];
    } else if (len1 == 0 || len2 == 0) {
      ans = 0;
    } else if (s1[len1 - 1] == s2[len2 - 1]) {
      dp[len1][len2] = 1 + lcs(s1, s2, len1 - 1, len2 - 1, dp);
      ans = dp[len1][len2];
    } else {
      dp[len1][len2] =
          max(lcs(s1, s2, len1, len2 - 1, dp), lcs(s1, s2, len1 - 1, len2, dp));
      ans = dp[len1][len2];
    }

    return ans;
  }
};
// Runtime: 112 ms, faster than 5.18%
// Memory Usage: 15.5 MB, less than 100.00%

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));
    return lcs(text1, text2, text1.size(), text2.size(), dp);
  }

  int lcs(string& s1, string& s2, int len1, int len2, vector<vector<int>>& dp) {
    if (dp[len1][len2] > 0) {
      return dp[len1][len2];
    }

    int ans = 0;

    if (len1 == 0 || len2 == 0) {
      ans = 0;
    } else if (s1[len1 - 1] == s2[len2 - 1]) {
      ans = 1 + lcs(s1, s2, len1 - 1, len2 - 1, dp);
    } else {
      ans =
          max(lcs(s1, s2, len1, len2 - 1, dp), lcs(s1, s2, len1 - 1, len2, dp));
    }

    dp[len1][len2] = ans;

    return ans;
  }
};
// Runtime: 128 ms, faster than 5.18%
// Memory Usage: 15.6 MB, less than 100.00%

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    return lcs(text1, text2, text1.size(), text2.size());
  }

  int lcs(string& s1, string& s2, int len1, int len2) {
    if (len1 == 0 || len2 == 0) {
      return 0;
    }

    if (s1[len1 - 1] == s2[len2 - 1]) {
      return 1 + lcs(s1, s2, len1 - 1, len2 - 1);
    }

    return max(lcs(s1, s2, len1, len2 - 1), lcs(s1, s2, len1 - 1, len2));
  }
};
// Time Limit Exceeded