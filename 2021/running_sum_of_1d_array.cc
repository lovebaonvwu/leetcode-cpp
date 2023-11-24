class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      nums[i] = nums[i - 1] + nums[i];
    }

    return nums;
  }
};
// Runtime: 4 ms, faster than 94.75%
// Memory Usage: 8.5 MB, less than 80.00%