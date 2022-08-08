class Solution {
 public:
  int longestIdealString(string s, int k) {
    int n = s.size();
    int ch[26];
    memset(ch, -1, sizeof(ch));

    vector<int> dp(n, 1);
    ch[s[0] - 'a'] = 0;

    for (int i = 1; i < n; ++i) {
      int lo = max(0, (s[i] - k) - 'a');
      int hi = min(25, (s[i] + k) - 'a');

      for (int j = lo; j <= hi; ++j) {
        int prev = ch[j] > -1 ? dp[ch[j]] : 0;
        dp[i] = max(dp[i], 1 + prev);
      }
      ch[s[i] - 'a'] = i;
    }

    return *max_element(dp.begin(), dp.end());
  }
};
// Runtime: 178 ms, faster than 85.71%
// Memory Usage: 13.8 MB, less than 85.71%
// 2022.8.8 at 奥盛大厦

class Solution {
 public:
  int longestIdealString(string s, int k) {
    int n = s.size();
    int ch[26];
    memset(ch, -1, sizeof(ch));

    vector<int> dp(n, 1);
    ch[s[0] - 'a'] = 0;

    int ans = 1;
    for (int i = 1; i < n; ++i) {
      int lo = max(0, (s[i] - k) - 'a');
      int hi = min(25, (s[i] + k) - 'a');

      for (int j = lo; j <= hi; ++j) {
        int prev = ch[j] > -1 ? dp[ch[j]] : 0;
        dp[i] = max(dp[i], 1 + prev);
      }
      ch[s[i] - 'a'] = i;

      ans = max(ans, dp[i]);
    }

    return ans;
  }
};
// Runtime: 174 ms, faster than 85.71%
// Memory Usage: 13.7 MB, less than 85.71%
// 2022.8.8 at 奥盛大厦