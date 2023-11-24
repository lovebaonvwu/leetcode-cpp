class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    int lo = 1;
    int hi = m * n;

    while (lo < hi) {
      int md = lo + (hi - lo) / 2;

      int cnt = 0;
      for (int i = 1; i <= m; ++i) {
        cnt += (md / i) <= n ? (md / i) : n;
      }

      if (cnt < k) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }

    return lo;
  }
};
// Runtime: 8 ms, faster than 98.64%
// Memory Usage: 6.3 MB, less than 14.97%