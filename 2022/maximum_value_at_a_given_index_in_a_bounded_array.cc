class Solution {
 public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;

    int lo = 0, hi = maxSum;

    while (lo < hi) {
      int md = (lo + hi + 1) / 2;

      if (sum(n, index, md) <= maxSum) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }

    return lo + 1;
  }

  long sum(int n, int index, int md) {
    int a = max(md - index, 0);
    long sum_left = (long)(md + a) * (md - a + 1) / 2;

    int b = max(md - (n - 1 - index), 0);
    long sum_right = (long)(md + b) * (md - b + 1) / 2;

    return sum_left + sum_right - md;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 74.72%
// 2022.5.7 at 奥盛大厦