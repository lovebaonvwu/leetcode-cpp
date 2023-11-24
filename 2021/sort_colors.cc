class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int r = 0;
    int w = 0;
    int b = 0;

    for (int& n : nums) {
      if (n == 2) {
        nums[b++] = 2;
      } else if (n == 1) {
        nums[b++] = 2;
        nums[w++] = 1;
      } else if (n == 0) {
        nums[b++] = 2;
        nums[w++] = 1;
        nums[r++] = 0;
      }
    }
  }
};  // 4ms

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int lo = 0, i = 0, hi = nums.size() - 1;

    while (i <= hi) {
      if (nums[i] == 1) {
        ++i;
      } else if (nums[i] == 0) {
        swap(nums[lo], nums[i]);
        ++lo;
        ++i;
      } else if (nums[i] == 2) {
        swap(nums[hi], nums[i]);
        --hi;
      }
    }
  }
};  // 4ms