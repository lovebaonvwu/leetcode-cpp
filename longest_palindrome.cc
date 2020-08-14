class Solution {
 public:
  int longestPalindrome(string s) {
    int cnt[256] = {};

    for (auto c : s) {
      ++cnt[c];
    }

    int ans = 0;

    int odd = 0;
    for (int i = 0; i < 256; ++i) {
      if (cnt[i] & 1) {
        odd = 1;
        ans += cnt[i] - 1;
      } else {
        ans += cnt[i];
      }
    }

    return ans + odd;
  }
};
// Runtime: 4 ms, faster than 96.35%
// Memory Usage: 6.8 MB, less than 30.83%

class Solution {
 public:
  int longestPalindrome(string s) {
    int cnt[256] = {};

    for (auto c : s) {
      ++cnt[c];
    }

    int odd = 0;
    for (int i = 0; i < 256; ++i) {
      odd += cnt[i] & 1;
    }

    return s.size() - odd + (odd > 0);
  }
};
// Runtime: 4 ms, faster than 96.35%
// Memory Usage: 6.5 MB, less than 88.37%