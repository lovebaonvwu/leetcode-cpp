class Solution {
 public:
  int nthMagicalNumber(int n, int a, int b) {
    long lo = 2, hi = ((unsigned long)1 << 63) - 1, mod = 1e9 + 7;
    int lcm = a * b / __gcd(a, b);

    while (lo < hi) {
      long md = lo + (hi - lo) / 2;

      if (md / a + md / b - md / lcm < n) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }

    return lo % mod;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 30.46%
// 2021.12.11 at 茗筑美嘉