class Solution {
 public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = INT_MAX;
    vector<int> cnt(32);
    for (int i = 0, j = 0, sum = 0; j < n; ++j) {
      for (int k = 0; k < 31; ++k) {
        if (nums[j] & (1 << k)) {
          ++cnt[k];
          if (cnt[k] == 1)
            sum += (1 << k);
        }
      }

      while (i <= j && sum >= k) {
        ans = min(ans, j - i + 1);

        for (int k = 0; k < 31; ++k) {
          if (nums[i] & (1 << k)) {
            --cnt[k];
            if (cnt[k] == 0)
              sum -= (1 << k);
          }
        }
        ++i;
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
// 109 ms
// 87.49 MB