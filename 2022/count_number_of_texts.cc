class Solution {
 public:
  int countTexts(string pressedKeys) {
    int n = pressedKeys.size();
    string& s = pressedKeys;

    vector<int> dp(n + 1);
    dp[0] = 1;

    int mod = 1e9 + 7;

    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1];
      int j = i - 1;

      if (j > 0 && s[j] == s[j - 1]) {
        dp[i] = (dp[i] + dp[i - 2]) % mod;

        if (j > 1 && s[j] == s[j - 2]) {
          dp[i] = (dp[i] + dp[i - 3]) % mod;

          if (j > 2 && (s[j] == '7' || s[j] == '9') && s[j] == s[j - 3]) {
            dp[i] = (dp[i] + dp[i - 4]) % mod;
          }
        }
      }
    }

    return dp[n];
  }
};
// Runtime: 57 ms, faster than 84.52%
// Memory Usage: 15.2 MB, less than 68.21%
// 2022.8.17 at 奥盛大厦