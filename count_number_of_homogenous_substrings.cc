class Solution {
 public:
  int countHomogenous(string s) {
    int ans = 0;

    for (int i = 0, cnt = 0; i < s.size(); ++i) {
      if (i == 0 || s[i] == s[i - 1]) {
        ++cnt;
      } else {
        cnt = 1;
      }

      ans = (ans + cnt) % 1000000007;
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 40.57%
// Memory Usage: 11.7 MB, less than 20.76%