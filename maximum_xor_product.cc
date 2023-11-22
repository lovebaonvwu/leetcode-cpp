class Solution {
 public:
  int maximumXorProduct(long long a, long long b, int n) {
    int mod = 1e9 + 7;
    if (n) {
      for (long long x = 1LL << (n - 1); x > 0; x >>= 1) {
        if ((a & x) && (b & x)) {
          continue;
        }

        if (!(a & x) && !(b & x)) {
          a ^= x;
          b ^= x;
        } else if (a & x) {
          if (a > b) {
            a ^= x;
            b ^= x;
          }
        } else if (b & x) {
          if (b > a) {
            a ^= x;
            b ^= x;
          }
        }
      }
    }

    return a % mod * (b % mod) % mod;
  }
};
// 4ms
// 6.19MB