class Solution {
 public:
  bool findSubarrays(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      for (int j = i + 1; j < nums.size() - 1; ++j) {
        if (nums[j] + nums[j + 1] == nums[i] + nums[i + 1]) {
          return true;
        }
      }
    }

    return false;
  }
};
// Runtime: 34 ms, faster than 5.22%
// Memory Usage: 7.5 MB, less than 84.08%
// 2022.9.10 at 茗筑美嘉