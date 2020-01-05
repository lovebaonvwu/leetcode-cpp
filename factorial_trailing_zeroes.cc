class Solution {
 public:
  int trailingZeroes(int n) {
    int ans = 0;

    for (long i = 5; i <= n; i *= 5) {
      ans += n / i;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.2 MB, less than 100.00%