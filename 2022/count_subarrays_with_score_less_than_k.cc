class Solution {
 public:
  long long countSubarrays(vector<int>& nums, long long k) {
    long long ans = 0, sum = 0;

    for (int i = 0, j = 0; i < nums.size(); ++i) {
      sum += nums[i];

      while (sum * (i - j + 1) >= k) {
        sum -= nums[j++];
      }

      ans += i - j + 1;
    }

    return ans;
  }
};
// Runtime: 186 ms, faster than 91.78%
// Memory Usage: 95 MB, less than 83.62%
// 2022.6.15 at 奥盛大厦