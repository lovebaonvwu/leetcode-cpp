class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();

    int ans = 0;

    for (int i = 0; i < n / 2; ++i) {
      ans = max(ans, nums[i] + nums[n - 1 - i]);
    }

    return ans;
  }
};
// Runtime: 208 ms, faster than 96.42%
// Memory Usage: 96.3 MB, less than 18.11%