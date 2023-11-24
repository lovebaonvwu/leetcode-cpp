class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> presum(n);

    presum[0] = nums[0];

    for (int i = 1; i < n; ++i) {
      presum[i] = presum[i - 1] + nums[i];
    }

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
      int left = (i + 1) * nums[i] - presum[i];
      int right = (presum[n - 1] - presum[i]) - (n - i - 1) * nums[i];

      ans[i] = left + right;
    }

    return ans;
  }
};
// Runtime: 216 ms, faster than 76.30%
// Memory Usage: 86 MB, less than 63.70%

class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> presum(n);

    int left = 0;
    int right = accumulate(nums.begin(), nums.end(), 0);

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
      right -= nums[i];
      left += nums[i];

      ans[i] = (nums[i] * (i + 1) - left) + (right - (n - i - 1) * nums[i]);
    }

    return ans;
  }
};
// Runtime: 208 ms, faster than 85.73%
// Memory Usage: 86 MB, less than 63.70%