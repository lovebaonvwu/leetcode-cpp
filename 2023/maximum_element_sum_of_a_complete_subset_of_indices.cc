class Solution {
 public:
  long long maximumSum(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      long long sum = 0;
      for (int k = 1; (i + 1) * k * k <= n; ++k) {
        sum += nums[(i + 1) * k * k - 1];
      }

      ans = max(ans, sum);
    }

    return ans;
  }
};
// 37ms
// 40.58MB