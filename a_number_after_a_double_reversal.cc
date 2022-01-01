class Solution {
 public:
  bool isSameAfterReversals(int num) {
    if (num == 0) {
      return true;
    }

    return (num % 10) != 0;
  }
};
// Runtime: 5 ms, faster than 14.10%
// Memory Usage: 5.9 MB, less than 70.61%
// 2022.1.1 at 茗筑美嘉