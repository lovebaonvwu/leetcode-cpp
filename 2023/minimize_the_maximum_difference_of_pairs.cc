class Solution {
 public:
  int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());

    int lo = 0, hi = nums.back() - nums[0];

    while (lo < hi) {
      int md = lo + (hi - lo) / 2;

      int cnt = 0;
      for (int i = 1; i < nums.size(); ++i) {
        if ((nums[i] - nums[i - 1]) <= md) {
          ++cnt;
          ++i;
        }
      }

      if (cnt >= p) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }

    return lo;
  }
};
// Runtime 202 ms
// Memory 81 MB