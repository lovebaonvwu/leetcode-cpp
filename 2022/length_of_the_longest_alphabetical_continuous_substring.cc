class Solution {
 public:
  int longestContinuousSubstring(string s) {
    s.append(1, '*');
    int n = s.size();

    int ans = 1;
    for (int i = 1, cnt = 1; i < n; ++i) {
      if (s[i] - s[i - 1] == 1) {
        ++cnt;
      } else {
        ans = max(ans, cnt);
        cnt = 1;
      }
    }

    return ans;
  }
};
// Runtime: 124 ms, faster than 20.53%
// Memory Usage: 18.1 MB, less than 7.49%
// 2022.9.20 at 奥盛大厦