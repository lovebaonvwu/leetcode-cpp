class Solution {
 public:
  int arithmeticTriplets(vector<int>& nums, int diff) {
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          if (nums[k] - nums[j] == diff &&
              nums[k] - nums[j] == nums[j] - nums[i]) {
            ++ans;
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 302 ms, faster than 25.00%
// Memory Usage: 8.6 MB, less than 25.00%
// 2022.8.14 at 茗筑美嘉