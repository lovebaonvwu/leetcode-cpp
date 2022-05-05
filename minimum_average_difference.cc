class Solution {
 public:
  int minimumAverageDifference(vector<int>& nums) {
    int n = nums.size();

    vector<long long> presum(n + 1);

    for (int i = 1; i <= n; ++i) {
      presum[i] = presum[i - 1] + nums[i - 1];
    }

    int ans = 0;
    long long minavg = LONG_MAX;

    for (int i = 0; i < n; ++i) {
      long long a = presum[i + 1] / (i + 1);
      long long b =
          (n - i - 1) == 0 ? 0 : (presum[n] - presum[i + 1]) / (n - i - 1);

      long long avg = abs(a - b);

      if (avg < minavg) {
        ans = i;
        minavg = avg;
      }
    }

    return ans;
  }
};
// Runtime: 123 ms, faster than 96.93%
// Memory Usage: 84.7 MB, less than 33.56%
// 2022.5.5 at 奥盛大厦