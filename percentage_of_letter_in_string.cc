class Solution {
 public:
  int percentageLetter(string s, char letter) {
    int cnt = 0;

    for (auto c : s) {
      cnt += c == letter;
    }

    return cnt * 100 / s.size();
  }
};
// Runtime: 4 ms, faster than 25.00%
// Memory Usage: 6.1 MB, less than 25.00%
// 2022.5.22 at 茗筑美嘉