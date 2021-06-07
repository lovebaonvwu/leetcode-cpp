class Solution {
 public:
  int countGoodSubstrings(string s) {
    unordered_map<char, int> mp;

    for (int i = 0; i < 3; ++i) {
      ++mp[s[i]];
    }

    int ans = mp.size() == 3 ? 1 : 0;

    for (int i = 3; i < s.size(); ++i) {
      --mp[s[i - 3]];

      if (mp[s[i - 3]] == 0) {
        mp.erase(s[i - 3]);
      }

      ++mp[s[i]];

      if (mp.size() == 3) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 26.61%
// Memory Usage: 6.7 MB, less than 24.98%

class Solution {
 public:
  int countGoodSubstrings(string s) {
    int ans = 0;

    for (int i = 2; i < s.size(); ++i) {
      if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 95.31%