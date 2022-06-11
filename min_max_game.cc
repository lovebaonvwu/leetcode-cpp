class Solution {
 public:
  int minMaxGame(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> newNums(nums.size() / 2);

    for (int i = 0; i < nums.size() / 2; ++i) {
      if (i % 2 == 0) {
        newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
      } else {
        newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
      }
    }

    return minMaxGame(newNums);
  }
};
// Runtime: 12 ms, faster than 47.99%
// Memory Usage: 9.9 MB, less than 63.46%
// 2022.6.11 at 奥盛大厦