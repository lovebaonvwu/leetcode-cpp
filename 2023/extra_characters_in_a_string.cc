class Solution {
 public:
  int minExtraChar(string s, vector<string>& dictionary) {
    int n = s.size();

    unordered_set<string> w(dictionary.begin(), dictionary.end());

    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i) {
      for (int len = 1; i + len <= n; ++len) {
        string t = s.substr(i, len);
        if (w.find(t) != w.end()) {
          dp[i] = min(dp[i], dp[i + len]);
        } else {
          dp[i] = min(dp[i], len + dp[i + len]);
        }
      }
    }

    return dp[0];
  }
};
// Runtime 190 ms
// Memory 81 MB