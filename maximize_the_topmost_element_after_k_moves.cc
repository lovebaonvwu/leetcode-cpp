class Solution {
 public:
  int maximumTop(vector<int>& nums, int k) {
    int n = nums.size();

    if (k == 0)
      return nums[0];
    if ((k & 1) && n == 1)
      return -1;

    int mx = 0;
    for (int i = 0; i < min(k - 1, n); ++i) {
      mx = max(mx, nums[i]);
    }

    if (k < n) {
      mx = max(mx, nums[k]);
    }

    return mx;
  }
};
// Runtime: 136 ms, faster than 75.65%
// Memory Usage: 63.5 MB, less than 71.05%
// 2022.4.21 at 奥盛大厦