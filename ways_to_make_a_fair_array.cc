class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    int n = nums.size();
    vector<int> sum(n);
    sum[n - 1] = nums[n - 1];
    if (n > 1) {
      sum[n - 2] = nums[n - 2];
    }

    for (int i = n - 3; i >= 0; --i) {
      sum[i] = nums[i] + sum[i + 2];
    }

    int odd = 0, even = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        ans += even + (i + 1 < n ? sum[i + 1] : 0) ==
               odd + (i + 2 < n ? sum[i + 2] : 0);
        even += nums[i];
      } else {
        ans += even + (i + 2 < n ? sum[i + 2] : 0) ==
               odd + (i + 1 < n ? sum[i + 1] : 0);
        odd += nums[i];
      }
    }

    return ans;
  }
};
// 105ms
// 99.19MB