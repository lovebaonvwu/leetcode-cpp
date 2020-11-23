class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int H) {
    int lo = 1, hi = 1000000000;

    while (lo < hi) {
      int md = lo + (hi - lo) / 2;

      int h = 0;
      for (auto p : piles) {
        h += (p + md - 1) / md;
      }

      if (h > H) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }

    return lo;
  }
};
// Runtime: 84 ms, faster than 41.53%
// Memory Usage: 19 MB, less than 93.15%