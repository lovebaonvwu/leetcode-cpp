class Solution {
 public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int ans = 0;

    while (pow(minutesToTest / minutesToDie + 1, ans) < buckets) {
      ++ans;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 31.86%