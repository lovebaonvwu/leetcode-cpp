class Solution {
 public:
  long long flowerGame(int n, int m) {
    int odd = (m + 1) / 2;
    int even = m / 2;

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % 2 == 0) {
        ans += odd;
      } else {
        ans += even;
      }
    }

    return ans;
  }
};
// 0ms
// 7.49MB

class Solution {
 public:
  long long flowerGame(int n, int m) {
    int n0 = n / 2;
    int n1 = (n + 1) / 2;
    int m0 = m / 2;
    int m1 = (m + 1) / 2;

    return 1LL * n0 * m1 + 1LL * n1 * m0;
  }
};
// 0 ms
// 7.65 MB