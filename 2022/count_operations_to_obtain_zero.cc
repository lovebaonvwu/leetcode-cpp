class Solution {
 public:
  int countOperations(int num1, int num2) {
    int ans = 0;

    while (num1 > 0 && num2 > 0) {
      ++ans;

      if (num1 >= num2) {
        num1 -= num2;
      } else {
        num2 -= num1;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 23.81%
// 2022.2.13 at 茗筑美嘉