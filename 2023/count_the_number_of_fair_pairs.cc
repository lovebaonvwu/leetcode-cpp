class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      auto lo = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
      auto hi = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);

      ans += (hi - lo);
    }

    return ans;
  }
};
// Runtime 286 ms
// Memory 53.6 MB
// 2023.2.13 at 奥盛大厦