class Solution {
 public:
  bool areOccurrencesEqual(string s) {
    int cnt[26] = {0};

    for (auto c : s) {
      ++cnt[c - 'a'];
    }

    int prev = -1;

    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > 0) {
        if (prev < 0) {
          prev = i;
        }

        if (cnt[prev] != cnt[i]) {
          return false;
        }
      }
    }

    return true;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 84.25%
// 2021.7.27 at 奥盛大厦