class Solution {
 public:
  long long maximumOr(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefix(n + 1), suffix(n + 1);
    for (int i = 1; i <= n; ++i) {
      prefix[i] = prefix[i - 1] | nums[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
      suffix[i] = suffix[i - 1] | nums[n - i];
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, prefix[i - 1 + 1] | ((long long)nums[i] << k) |
                         suffix[n - i - 1]);
    }

    return ans;
  }
};
// 194ms
// 88.88mb