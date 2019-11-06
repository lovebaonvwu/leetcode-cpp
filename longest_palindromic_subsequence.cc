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