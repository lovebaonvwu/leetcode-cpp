class Solution {
 public:
  int countQuadruplets(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          for (int l = k + 1; l < n; ++l) {
            if (nums[i] + nums[j] + nums[k] == nums[l]) {
              ++ans;
            }
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 242 ms, faster than 22.87%
// Memory Usage: 10.6 MB, less than 48.32%
// 2022.2.4 at 茗筑美嘉