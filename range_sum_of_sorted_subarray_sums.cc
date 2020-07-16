class Solution {
 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> presum(n + 1);

    for (int i = 1; i < n + 1; ++i) {
      presum[i] = presum[i - 1] + nums[i - 1];
    }

    vector<int> sum;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n + 1; ++j) {
        sum.push_back(presum[j] - presum[i]);
      }
    }

    sort(sum.begin(), sum.end());

    int ans = 0;
    for (int i = left - 1; i < right; ++i) {
      ans += sum[i];
      ans %= static_cast<int>(1e9 + 7);
    }

    return ans;
  }
};
// Runtime: 900 ms, faster than 23.75%
// Memory Usage: 24 MB, less than 100.00%