class Solution {
 public:
  int waysToSplit(vector<int>& nums) {
    partial_sum(begin(nums), end(nums), begin(nums));

    int ans = 0;
    int n = nums.size();

    for (int i = 0, j = 0, k = 0; i < n - 2; ++i) {
      j = max(i + 1, j);

      while (j < n - 1 && nums[j] - nums[i] < nums[i]) {
        ++j;
      }

      k = max(j, k);

      while (k < n - 1 && nums[n - 1] - nums[k] >= nums[k] - nums[i]) {
        ++k;
      }

      ans = (ans + k - j) % 1000000007;
    }

    return ans;
  }
};
// Runtime: 171 ms, faster than 89.84%
// Memory Usage: 81.2 MB, less than 97.62%
// 2022.5.18 at 奥盛大厦