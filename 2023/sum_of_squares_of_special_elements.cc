class Solution {
 public:
  int sumOfSquares(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (n % (i + 1) == 0) {
        ans += nums[i] * nums[i];
      }
    }

    return ans;
  }
};
// 14ms
// 35.74MB