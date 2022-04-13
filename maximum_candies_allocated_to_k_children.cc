class Solution {
 public:
  int maximumCandies(vector<int>& candies, long long k) {
    int lo = 0, hi = 1e7;

    while (lo < hi) {
      int md = (lo + hi + 1) / 2;

      long long cnt = 0;
      for (auto c : candies) {
        cnt += c / md;
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
// Runtime: 195 ms, faster than 93.01%
// Memory Usage: 84.4 MB, less than 12.77%