class Solution {
 public:
  long long repairCars(vector<int>& ranks, int cars) {
    long long lo = 1, hi = 100 * pow(10, 12);

    while (lo < hi) {
      long long md = (lo + hi) / 2;

      long long cnt = 0;
      for (auto r : ranks) {
        cnt += sqrt(md / r);
      }

      if (cnt < cars) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }

    return lo;
  }
};
// Runtime 160 ms
// Memory 53.6 MB