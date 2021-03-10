class Solution {
 public:
  bool isUgly(int num) {
    if (num <= 0) {
      return false;
    }

    while (num % 2 == 0) {
      num /= 2;
    }

    while (num % 3 == 0) {
      num /= 3;
    }

    while (num % 5 == 0) {
      num /= 5;
    }

    return num == 1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 77.70%