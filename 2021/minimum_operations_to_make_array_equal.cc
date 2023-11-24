class Solution {
 public:
  int minOperations(int n) {
    int ans = 0;

    if (n & 1) {
      ans = (2 + (2 * (n / 2))) * (n / 2) / 2;
    } else {
      ans = (1 + (2 * (n / 2 - 1) + 1)) * (n / 2) / 2;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 43.19%
// Memory Usage: 5.9 MB, less than 79.59%