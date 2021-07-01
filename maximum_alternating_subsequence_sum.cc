class Solution {
 public:
  long long maxAlternatingSum(vector<int>& nums) {
    long long ans = 0;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] > nums[i]) {
        ans += nums[i - 1] - nums[i];
      }
    }

    return ans + nums.back();
  }
};
// Runtime: 168 ms, faster than 73.01%
// Memory Usage: 91.1 MB, less than 59.42%