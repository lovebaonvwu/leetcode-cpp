class Solution {
 public:
  int minSpeedOnTime(vector<int>& dist, double hour) {
    int lo = 1, hi = INT_MAX / 2;

    if ((dist.size() - 1) >= hour) {
      return -1;
    }

    while (lo < hi) {
      int md = (lo + hi) / 2;
      double t = 0;

      for (int i = 0; i < dist.size() - 1; ++i) {
        t += (dist[i] + md - 1) / md;
      }

      t += (double)dist.back() / md;

      if (t > hour) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }

    return lo;
  }
};
// Runtime: 796 ms, faster than 30.62%
// Memory Usage: 101.5 MB, less than 47.43%
// 2022.10.25 at 奥盛大厦