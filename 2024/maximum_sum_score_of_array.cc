class Solution {
 public:
  long long maximumSumScore(vector<int>& nums) {
    int n = nums.size();
    vector<long long> presum(n + 1);
    for (int i = 1; i <= n; ++i) {
      presum[i] = presum[i - 1] + nums[i - 1];
    }

    long long ans = LONG_MIN;
    for (int i = 0; i < n; ++i) {
      long long cur = max(presum[i + 1], presum[n] - presum[i]);
      ans = max(ans, cur);
    }

    return ans;
  }
};
// 47 ms
// 45.13 MB
