class Solution {
 public:
  vector<long long> distance(vector<int>& nums) {
    unordered_map<int, long long> cnt, sum;

    int n = nums.size();
    vector<long long> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = cnt[nums[i]] * i - sum[nums[i]];
      sum[nums[i]] += i;
      cnt[nums[i]] += 1;
    }

    cnt.clear();
    sum.clear();
    for (int i = n - 1; i >= 0; --i) {
      ans[i] += cnt[nums[i]] * (n - i - 1) - sum[nums[i]];
      sum[nums[i]] += (n - i - 1);
      cnt[nums[i]] += 1;
    }

    return ans;
  }
};
// Runtime 359 ms
// Memory 115.8 MB