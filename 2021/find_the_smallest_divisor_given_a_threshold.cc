class Solution {
  int getSmallestDivisor(const vector<int>& nums, int d) {
    int res = 0;

    for (auto n : nums) {
      res += n / d;
      res += (n % d) > 0;
    }

    return res;
  }

 public:
  int smallestDivisor(vector<int>& nums, int threshold) {
    int lo = 1;
    int hi = *max_element(nums.begin(), nums.end()) + 1;

    while (lo <= hi) {
      int md = lo + (hi - lo) / 2;

      int sd = getSmallestDivisor(nums, md);

      if (sd > threshold) {
        lo = md + 1;
      } else {
        hi = md - 1;
      }
    }

    return lo;
  }
};
// Runtime: 68 ms, faster than 71.87%
// Memory Usage: 20.3 MB, less than 5.72%