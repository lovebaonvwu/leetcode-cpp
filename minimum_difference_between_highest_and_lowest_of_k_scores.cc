class Solution {
 public:
  int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int ans = INT_MAX;

    for (int i = 0; i < nums.size() - k + 1; ++i) {
      ans = min(ans, nums[i + k - 1] - nums[i]);
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 82.57%
// Memory Usage: 13.7 MB, less than 23.33%
// 2021.10.10 at 茗筑美嘉