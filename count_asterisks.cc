class Solution {
 public:
  int countAsterisks(string s) {
    int ans = 0, cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '|') {
        ++cnt;
      } else if (s[i] == '*' && (cnt % 2 == 0)) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 8.41%
// Memory Usage: 6.4 MB, less than 78.74%
// 2022.7.3 at 茗筑美嘉