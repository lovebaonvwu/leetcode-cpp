class Solution {
 public:
  int minimumMoves(string s) {
    int ans = 0;

    for (int i = 0; i < s.size();) {
      if (s[i] == 'O') {
        ++i;
        continue;
      }

      ++ans;
      i += 3;
    }

    return ans;
  }
};
// Runtime: 3 ms, faster than 66.67%
// Memory Usage: 6.4 MB, less than 80.00%
// 2021.10.04 at 茗筑美嘉