class Solution {
 public:
  int minimumRightShifts(vector<int>& nums) {
    int i = nums.back() > nums[0] ? 0 : -1;
    for (int j = 1; j < nums.size(); ++j) {
      if (nums[j] < nums[j - 1]) {
        if (i == -1) {
          i = j;
        } else {
          return -1;
        }
      }
    }

    return (i == -1 || i == 0) ? 0 : nums.size() - i;
  }
};
// 4ms
// 23.02MB