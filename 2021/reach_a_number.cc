class Solution {
 public:
  int reachNumber(int target) {
    int n = 1;

    int sum = 0;

    target = abs(target);

    while (sum < target) {
      sum += n;
      ++n;
    }

    while ((sum - target) % 2 != 0) {
      sum += n;
      ++n;
    }

    return n - 1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 90.54%