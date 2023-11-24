class Solution {
 public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size();
    vector<int> ans(n);

    int val = (1 << maximumBit) - 1;

    for (int i = 0; i < n; ++i) {
      ans[n - i - 1] = val ^ nums[i];
      val ^= nums[i];
    }

    return ans;
  }
};
// Runtime: 297 ms, faster than 22.77%
// Memory Usage: 92.7 MB, less than 93.38%
// 2022.2.16 at 奥盛大厦