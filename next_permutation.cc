class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int m = -1;
    int n = -1;

    for (int i = nums.size() - 1; i > 0; --i) {
      if (nums[i] > nums[i - 1]) {
        m = i - 1;
        break;
      }
    }

    if (m < 0) {
      reverse(nums.begin(), nums.end());
      return;
    }

    for (int i = nums.size() - 1; i > 0; --i) {
      if (nums[i] > nums[m]) {
        n = i;
        break;
      }
    }

    swap(nums[m], nums[n]);

    reverse(nums.begin() + m + 1, nums.end());
  }
};  // 4ms