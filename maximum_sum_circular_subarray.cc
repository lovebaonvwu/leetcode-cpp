class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;

    for (int i = 0; i < n; ++i) {
      curMax = max(curMax + nums[i], nums[i]);
      maxSum = max(curMax, maxSum);
      curMin = min(curMin + nums[i], nums[i]);
      minSum = min(curMin, minSum);

      total += nums[i];
    }

    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
  }
};
// Runtime 62 ms
// Memory 40 MB
// 2023.1.18 at 奥盛大厦