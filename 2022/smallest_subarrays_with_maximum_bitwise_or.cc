class Solution {
 public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    int prev[30] = {0};
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < 30; ++j) {
        if (nums[i] & (1 << j)) {
          prev[j] = i;
        }

        ans[i] = max(ans[i], prev[j] - i + 1);
      }
    }

    return ans;
  }
};
// Runtime: 289 ms, faster than 79.67%
// Memory Usage: 56 MB, less than 66.16%
// 2022.10.10 at 奥盛大厦