class Solution {
 public:
  int minimumLength(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
      if (s[i] != s[j]) {
        break;
      }

      while (i + 1 < j && s[i + 1] == s[i]) {
        ++i;
      }

      while (j - 1 > i && s[j - 1] == s[j]) {
        --j;
      }

      ++i, --j;
    }

    return j - i + 1;
  }
};
// Runtime: 40 ms, faster than 32.57%
// Memory Usage: 12.6 MB, less than 93.16%
// 2022.6.8 at 奥盛大厦