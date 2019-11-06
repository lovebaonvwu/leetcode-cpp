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