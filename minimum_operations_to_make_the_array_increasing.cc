class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();

    for (int i = 1; i < n; ++i) {
      int inc = max(0, nums[i - 1] - nums[i] + 1);

      nums[i] += inc;

      ans += inc;
    }

    return ans;
  }
};
// Runtime: 11 ms, faster than 81.75%
// Memory Usage: 15.8 MB, less than 73.45%
// 2021.8.13 at 奥盛大厦