class Solution {
 public:
  char repeatedCharacter(string s) {
    int cnt[26] = {0};

    for (auto c : s) {
      if (cnt[c - 'a'] > 0) {
        return c;
      }

      ++cnt[c - 'a'];
    }

    return ' ';
  }
};
// Runtime: 3 ms, faster than 25.00%
// Memory Usage: 5.9 MB, less than 75.00%
// 2022.7.24 at 茗筑美嘉