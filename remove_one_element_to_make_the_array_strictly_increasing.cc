class Solution {
 public:
  bool canBeIncreasing(vector<int>& nums) {
    int cnt = 0;

    for (int i = 1; i < nums.size() && cnt < 2; ++i) {
      if (nums[i] <= nums[i - 1]) {
        ++cnt;

        if (i > 1 && nums[i] <= nums[i - 2]) {
          nums[i] = nums[i - 1];
        }
      }
    }

    return cnt < 2;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 9.8 MB, less than 84.04%
// 2021.12.23 at 奥盛大厦