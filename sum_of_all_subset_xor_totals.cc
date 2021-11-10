class Solution {
 public:
  int subsetXORSum(vector<int>& nums) {
    int ans = 0;

    int n = nums.size();

    for (int i = pow(2, n) - 1; i >= 0; --i) {
      int sum = 0;

      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          sum ^= nums[j];
        }
      }

      ans += sum;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 72.48%
// Memory Usage: 7.2 MB, less than 53.84%
// 2021.11.10 at 奥盛大厦