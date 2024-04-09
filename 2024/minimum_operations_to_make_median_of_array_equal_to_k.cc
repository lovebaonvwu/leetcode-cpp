class Solution {
 public:
  long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));

    int n = nums.size();

    long long ans = 0;
    if (nums[n / 2] == k)
      return ans;

    if (nums[n / 2] > k) {
      for (int i = n / 2; i >= 0 and nums[i] > k; --i) {
        ans += nums[i] - k;
      }
    } else {
      for (int i = n / 2; i < n && nums[i] < k; ++i) {
        ans += k - nums[i];
      }
    }

    return ans;
  }
};
// 133 ms
// 89.22 MB