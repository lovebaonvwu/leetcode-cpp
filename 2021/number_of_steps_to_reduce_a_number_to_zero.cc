class Solution {
 public:
  int numberOfSteps(int num) {
    int ans = 0;

    while (num) {
      if (num & 1) {
        --num;
      } else {
        num >>= 1;
      }

      ++ans;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 75.00%
// Memory Usage: 8.2 MB, less than 100.00%

class Solution {
 public:
  int numberOfSteps(int num) {
    return num == 0 ? 0
                    : 1 + (num & 1 ? numberOfSteps(num - 1)
                                   : numberOfSteps(num / 2));
  }
};
// Runtime: 4 ms, faster than 75.00%
// Memory Usage: 8.3 MB, less than 100.00%