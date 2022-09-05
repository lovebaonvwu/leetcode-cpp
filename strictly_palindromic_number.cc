class Solution {
 public:
  bool isStrictlyPalindromic(int n) {
    for (int b = 2; b <= n - 2; ++b) {
      string s;
      int t = n;

      while (t) {
        s += (t % b) + '0';
        t /= b;
      }

      for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
          return false;
        }
      }
    }

    return true;
  }
};
// Runtime: 2 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%
// 2022.9.5 at 奥盛大厦