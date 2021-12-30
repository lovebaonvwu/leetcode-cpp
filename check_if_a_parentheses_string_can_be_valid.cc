class Solution {
 public:
  bool canBeValid(string s, string locked) {
    if (s.size() & 1) {
      return false;
    }

    for (int i = 0, balance = 0; i < s.size(); ++i) {
      if (s[i] == ')' && locked[i] == '1') {
        --balance;
      } else {
        ++balance;
      }

      if (balance < 0) {
        return false;
      }
    }

    for (int i = s.size() - 1, balance = 0; i >= 0; --i) {
      if (s[i] == '(' && locked[i] == '1') {
        --balance;
      } else {
        ++balance;
      }

      if (balance < 0) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 154 ms, faster than 12.12%
// Memory Usage: 27.2 MB, less than 43.01%
// 2021.12.30 at 奥盛大厦