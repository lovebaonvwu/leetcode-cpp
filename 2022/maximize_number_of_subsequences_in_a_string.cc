class Solution {
 public:
  long long maximumSubsequenceCount(string text, string pattern) {
    long long ans = 0, cnt0 = 0, cnt1 = 0;

    for (auto ch : text) {
      if (ch == pattern[1]) {
        ans += cnt0;
        ++cnt1;
      }

      if (ch == pattern[0]) {
        ++cnt0;
      }
    }

    return ans + max(cnt0, cnt1);
  }
};
// Runtime: 51 ms, faster than 94.53%
// Memory Usage: 16.7 MB, less than 87.18%
// 2022.4.2 at 奥盛大厦