class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }

    long ans = 0, a = abs(dividend), b = abs(divisor);

    while (a >= b) {
      long t = b, cnt = 1;

      while ((t << 1) <= a) {
        t <<= 1;
        cnt <<= 1;
      }

      ans += cnt;
      a -= t;
    }

    return (dividend > 0) ^ (divisor > 0) ? -ans : ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.8 MB, less than 82.75%