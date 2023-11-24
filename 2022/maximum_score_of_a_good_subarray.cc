class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    int i = k, j = k, n = nums.size();

    int ans = nums[k], cur = nums[k];

    while (i < n - 1 || j > 0) {
      if (j == 0) {
        ++i;
      } else if (i == n - 1) {
        --j;
      } else if (nums[i + 1] > nums[j - 1]) {
        ++i;
      } else {
        --j;
      }

      cur = min(cur, min(nums[i], nums[j]));
      ans = max(ans, cur * (i - j + 1));
    }

    return ans;
  }
};
// Runtime: 268 ms, faster than 42.96%
// Memory Usage: 89.5 MB, less than 60.86%
// 2022.1.29 at 奥盛大厦