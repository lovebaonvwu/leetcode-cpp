class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int ans = 0;
    long long sum = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      sum += nums[j];

      while (1LL * nums[j] * (j - i + 1) - sum > k) {
        sum -= nums[i++];
      }

      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
// 159ms
// 99.31MB