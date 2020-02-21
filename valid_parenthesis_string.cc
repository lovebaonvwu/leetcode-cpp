class Solution {
 public:
  bool checkValidString(string s) {
    int lo = 0;
    int hi = 0;

    for (auto c : s) {
      if (c == '(') {
        ++lo;
        ++hi;
      } else if (c == ')') {
        --lo;
        --hi;
      } else {
        --lo;
        ++hi;
      }

      if (hi < 0) {
        return false;
      }

      if (lo < 0) {
        lo = 0;
      }
    }

    return lo == 0;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.4 MB, less than 28.57%

class Solution {
 public:
  bool checkValidString(string s) {
    int max_op = 0;
    int min_op = 0;

    for (char c : s) {
      if (c == '(') {
        ++min_op;
      } else {
        --min_op;
      }

      if (c == ')') {
        --max_op;
      } else {
        ++max_op;
      }

      if (max_op < 0) {
        return false;
      }

      min_op = max(min_op, 0);
    }

    return min_op == 0;
  }
};
// Runtime: 4 ms, faster than 67.50%
// Memory Usage: 8.2 MB, less than 85.71%