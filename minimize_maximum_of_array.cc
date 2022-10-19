class Solution {
 public:
  int minimizeArrayValue(vector<int>& nums) {
    long long ans = 0;
    long long sum = 0;

    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      ans = max(ans, (sum + i) / (i + 1));
    }

    return ans;
  }
};
// Runtime: 120 ms, faster than 99.45%
// Memory Usage: 71.4 MB, less than 57.63%
// 2022.10.19 at 奥盛大厦