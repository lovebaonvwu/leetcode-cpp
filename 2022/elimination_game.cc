class Solution {
 public:
  int lastRemaining(int n) {
    int ans = 1, step = 1;

    bool l2r = true;

    while (n > 1) {
      if (l2r) {
        ans += step;
      } else {
        if (n & 1) {
          ans += step;
        }
      }

      step *= 2;
      n /= 2;

      l2r = !l2r;
    }

    return ans;
  }
};
// Runtime: 10 ms, faster than 10.93%
// Memory Usage: 5.8 MB, less than 69.13%
// 2022.1.5 at 奥盛大厦

class Solution {
 public:
  int lastRemaining(int n) {
    return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
  }
};
// Runtime: 3 ms, faster than 65.92%
// Memory Usage: 6 MB, less than 28.62%
// 2022.1.5 at 奥盛大厦