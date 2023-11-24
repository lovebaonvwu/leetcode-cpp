class Solution {
 public:
  int rearrangeCharacters(string s, string target) {
    int tar[26] = {0};
    for (auto c : target) {
      ++tar[c - 'a'];
    }

    int cur[26] = {0};
    for (auto c : s) {
      ++cur[c - 'a'];
    }

    int ans = INT_MAX;
    for (int i = 0; i < 26; ++i) {
      if (tar[i] > 0) {
        ans = min(ans, cur[i] / tar[i]);
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 66.67%
// 2022.5.29 at 茗筑美嘉