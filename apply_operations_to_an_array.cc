class Solution {
 public:
  vector<int> applyOperations(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
    }

    int n = nums.size();
    for (int i = 0, j = 0; j < n;) {
      while (i < n && nums[i] != 0) {
        ++i;
      }

      j = i + 1;
      while (j < n && nums[j] == 0) {
        ++j;
      }

      if (i < n && j < n) {
        swap(nums[i], nums[j]);
      }
    }

    return nums;
  }
};
// Runtime 17ms
// Memory 8.7MB
// 2022.11.6 at 茗筑美嘉