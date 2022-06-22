class Solution {
 public:
  int longestSubsequence(string s, int k) {
    int cnt = 0;
    int pow = 1;
    int cur = 0;
    for (int i = s.size() - 1; i >= 0 && cur + pow <= k; --i) {
      if (s[i] == '1') {
        ++cnt;
        cur += pow;
      }

      pow <<= 1;
    }

    return count(s.begin(), s.end(), '0') + cnt;
  }
};
// Runtime: 4 ms, faster than 67.41%
// Memory Usage: 6.7 MB, less than 61.81%
// 2022.6.22 at 奥盛大厦