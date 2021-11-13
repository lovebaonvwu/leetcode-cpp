class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int ans = nums[0], sum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        sum += nums[i];
      } else {
        sum = nums[i];
      }

      ans = max(ans, sum);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.4 MB, less than 39.49%
// 2021.11.13 at 茗筑美嘉