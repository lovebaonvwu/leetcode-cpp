class Solution {
 public:
  int findSubstringInWraproundString(string s) {
    int n = s.size();
    vector<int> dp(n, 1);
    int cnt[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
      if (i > 0 && ((s[i] == 'a' && s[i - 1] == 'z') || s[i] - s[i - 1] == 1)) {
        dp[i] = dp[i - 1] + 1;
      }

      cnt[s[i] - 'a'] = max(cnt[s[i] - 'a'], dp[i]);
    }

    int ans = accumulate(begin(cnt), end(cnt), 0);

    return ans;
  }
};
// 8ms
// 9.82MB