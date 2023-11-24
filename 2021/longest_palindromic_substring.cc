class Solution {
 public:
  string longestPalindrome(string s) {
    int left = 0;
    int right = 0;

    for (int i = 0; i < s.size(); ++i) {
      int len1 = pal(s, i, i);
      int len2 = pal(s, i, i + 1);

      int maxLen = max(len1, len2);

      if (maxLen > right - left) {
        left = i - ((maxLen - 1) / 2);
        right = i + (maxLen / 2);
      }
    }

    return s.substr(left, right - left + 1);
  }

  int pal(string& s, int i, int j) {
    if (s.empty() || i > j) {
      return 0;
    }

    while (i >= 0 && j < s.size() && s[i] == s[j]) {
      --i;
      ++j;
    }

    return j - i - 1;
  }
};
// Runtime: 44 ms, faster than 65.30%
// Memory Usage: 6.8 MB, less than 100.00%