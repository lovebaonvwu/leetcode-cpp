class Solution {
 public:
  bool canSortArray(vector<int>& nums) {
    int n = nums.size();
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n - 1; ++j) {
        if (nums[j] > nums[j + 1]) {
          if (__builtin_popcount(nums[j]) != __builtin_popcount(nums[j + 1])) {
            return false;
          }

          swap(nums[j], nums[j + 1]);
        }
      }
    }

    return true;
  }
};
// 10ms
// 30.78MB