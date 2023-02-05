class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int chars[256] = {0};
    int cnt = 0;

    int ans = 0;
    for (int i = 0, j = 0; i < s.size(); ++i) {
      ++chars[s[i]];
      if (chars[s[i]] == 1) {
        ++cnt;
      }

      while (cnt > 2) {
        --chars[s[j]];
        if (chars[s[j]] == 0) {
          --cnt;
        }
        ++j;
      }

      ans = max(ans, i - j + 1);
    }

    return ans;
  }
};
// Runtime 16 ms
// Memory 9.5 MB
// 2023.2.4 at 奥盛大厦