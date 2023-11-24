class Solution {
 public:
  int countOrders(int n) {
    long ans = 1, mod = 1e9 + 7;

    for (int i = 1; i <= n; ++i) {
      ans *= i;
      ans %= mod;
      ans *= (2 * i - 1);
      ans %= mod;
    }

    return (int)ans;
  }
};
// Runtime: 2 ms, faster than 53.46%
// Memory Usage: 6 MB, less than 53.14%
// 2022.3.6 at 奥盛大厦