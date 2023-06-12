class Solution {
 public:
  int longestSemiRepetitiveSubstring(string s) {
    int ans = 0;

    for (int i = 0, j = 0, k = -1; j < s.size(); ++j) {
      if (j > 0 && s[j] == s[j - 1]) {
        if (k > 0) {
          ans = max(ans, j - 1 - i + 1);
          i = k;
        }

        k = j;
      }

      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
// Runtime 23 ms
// Memory 6.3 MB