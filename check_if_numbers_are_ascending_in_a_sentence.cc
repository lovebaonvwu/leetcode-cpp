class Solution {
 public:
  bool areNumbersAscending(string s) {
    int prev = 0, cur = 0;

    s += ' ';

    for (auto c : s) {
      if (isalpha(c)) {
        cur = 0;
        continue;
      }

      if (c == ' ') {
        if (cur == 0) {
          continue;
        }

        if (cur > prev) {
          prev = cur;
          cur = 0;
          continue;
        }

        return false;
      }

      cur = cur * 10 + (c - '0');
    }

    return true;
  }
};
// Runtime: 3 ms, faster than 39.53%
// Memory Usage: 6.5 MB, less than 15.87%
// 2021.10.23 at 茗筑美嘉

class Solution {
 public:
  bool areNumbersAscending(string s) {
    int prev = 0, cur = 0;

    s += ' ';

    for (auto c : s) {
      if (isdigit(c)) {
        cur = cur * 10 + (c - '0');
      } else if (cur > 0) {
        if (cur <= prev) {
          return false;
        }

        prev = cur;
        cur = 0;
      }
    }

    return true;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 15.87%
// 2021.10.23 at 茗筑美嘉