class Solution {
 public:
  int minCapability(vector<int>& nums, int k) {
    int lo = *min_element(begin(nums), end(nums));
    int hi = *max_element(begin(nums), end(nums));

    while (lo < hi) {
      int md = (lo + hi) / 2;

      int cnt = 0;
      for (int i = 0; i < nums.size();) {
        if (nums[i] <= md) {
          ++cnt;
          i += 2;
        } else {
          ++i;
        }
      }

      if (cnt >= k) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }

    return lo;
  }
};
// Runtime 177 ms
// Memory 56.9 MB
// Binary Search