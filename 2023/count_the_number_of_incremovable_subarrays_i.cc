class Solution {
 public:
  int incremovableSubarrayCount(vector<int>& nums) {
    int n = nums.size();
    int j = n - 1;
    while (j > 0 && nums[j - 1] < nums[j])
      --j;

    if (j == 0)
      return (1 + n) * n / 2;

    int ans = n - j + 1;
    for (int i = 1; i < n; ++i) {
      while (j < n && nums[i - 1] >= nums[j])
        ++j;
      ans += n - j + 1;
      if (nums[i] <= nums[i - 1])
        break;
    }

    return ans;
  }
};
// 8ms
// 19.03MB