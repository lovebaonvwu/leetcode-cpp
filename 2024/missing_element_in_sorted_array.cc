class Solution {
 public:
  int missingElement(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] - 1 >= k) {
        return nums[i - 1] + k;
      } else {
        k -= nums[i] - nums[i - 1] - 1;
      }
    }

    return nums[n - 1] + k;
  }
};
// 35 ms
// 34.17 MB
