class Solution {
 public:
  int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] % 2 != 0 || nums[i] > threshold)
        continue;
      int j = i;
      for (; j < n - 1 && nums[j] <= threshold && nums[j + 1] <= threshold;
           ++j) {
        if (nums[j] % 2 == nums[j + 1] % 2)
          break;
      }

      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
// 99ms
// 91.39MB