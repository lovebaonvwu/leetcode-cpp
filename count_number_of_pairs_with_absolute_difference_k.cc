class Solution {
 public:
  int countKDifference(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    int ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      int target1 = nums[i] + k;
      int target2 = nums[i] - k;

      if (mp.find(target1) != mp.end()) {
        ans += mp[target1];
      }

      if (mp.find(target2) != mp.end()) {
        ans += mp[target2];
      }

      ++mp[nums[i]];
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 55.83%
// Memory Usage: 13.5 MB, less than 16.57%
// 2021.10.01 at 茗筑美嘉