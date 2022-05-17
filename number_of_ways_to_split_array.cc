class Solution {
 public:
  int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();

    vector<long long> presum(n);
    presum[0] = nums[0];

    for (int i = 1; i < n; ++i) {
      presum[i] = presum[i - 1] + nums[i];
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      ans += (presum[i] >= presum[n - 1] - presum[i]);
    }

    return ans;
  }
};
// Runtime: 201 ms, faster than 81.21%
// Memory Usage: 92.7 MB, less than 32.04%
// 2022.5.17 at 奥盛大厦

class Solution {
 public:
  int waysToSplitArray(vector<int>& nums) {
    long long right = accumulate(begin(nums), end(nums), 0LL);

    long long left = 0;
    int ans = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      left += nums[i];
      right -= nums[i];

      ans += left >= right;
    }

    return ans;
  }
};
// Runtime: 285 ms, faster than 30.14%
// Memory Usage: 85.6 MB, less than 67.50%
// 2022.5.17 at 奥盛大厦