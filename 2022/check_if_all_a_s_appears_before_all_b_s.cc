class Solution {
 public:
  bool checkString(string s) {
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == 'a' && s[i - 1] == 'b') {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 4 ms, faster than 26.15%
// Memory Usage: 6.2 MB, less than 56.03%
// 2022.1.8 at 茗筑美嘉