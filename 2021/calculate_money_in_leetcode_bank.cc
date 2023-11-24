class Solution {
 public:
  int totalMoney(int n) {
    int ans = 0;

    for (int i = 1, a = 0, b = 1; i <= n; ++i) {
      ans += a + b;

      if (7 == b++) {
        ++a;
        b = 1;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 90.18%

class Solution {
 public:
  int totalMoney(int n) {
    int ans = 0;

    int weeks = n / 7;

    ans += ((1 + 7) * 7) / 2 * weeks;
    ans += (0 + 7 * (weeks - 1)) * weeks / 2;
    ans +=
        ((weeks + 1) + (weeks + 1 + (n - weeks * 7 - 1))) * (n - weeks * 7) / 2;

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 53.02%