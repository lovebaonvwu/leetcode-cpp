class Solution {
 public:
  double myPow(double x, int n) {
    double ans = 1;

    long m = n;

    m = m < 0 ? -m : m;

    while (m > 0) {
      if (m & 1) {
        ans *= x;
      }

      x *= x;

      m >>= 1;
    }

    return n > 0 ? ans : 1 / ans;
  }
};