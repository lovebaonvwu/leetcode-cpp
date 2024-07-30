class Solution {
 public:
  int maxLength(vector<int>& ribbons, int k) {
    int lo = 0, hi = 100000;

    while (lo < hi) {
      int md = (lo + hi + 1) / 2;
      int cnt = 0;
      for (auto r : ribbons) {
        cnt += r / md;
      }

      if (cnt < k) {
        hi = md - 1;
      } else {
        lo = md;
      }
    }

    return lo;
  }
};
// 135 ms
// 95.13 MB
