class Solution {
 public:
  int maxPower(string s) {
    int ans = 1;
    char prev = s[0];

    for (int i = 1, cnt = 1; i < s.size(); ++i) {
      if (s[i] == prev) {
        ++cnt;
      } else {
        cnt = 1;
        prev = s[i];
      }
      ans = max(ans, cnt);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 92.79%
// Memory Usage: 7.1 MB, less than 100.00%