class Solution {
 public:
  long long incremovableSubarrayCount(vector<int>& nums) {
    int n = nums.size();
    int j = n - 1;
    while (j > 0 && nums[j] > nums[j - 1])
      --j;

    if (j == 0)
      return 1LL * (1 + n) * n / 2;

    long long ans = n - j + 1;
    for (int i = 1; i < n; ++i) {
      while (j < n && nums[i - 1] >= nums[j])
        ++j;
      ans += n - j + 1;
      if (nums[i - 1] >= nums[i])
        break;
    }

    return ans;
  }
};
// 311ms
// 94.89MB