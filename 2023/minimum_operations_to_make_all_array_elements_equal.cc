class Solution {
 public:
  vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<long long> presum(n + 1);

    for (int i = 1; i <= n; ++i) {
      presum[i] = presum[i - 1] + nums[i - 1];
    }

    vector<long long> ans;

    for (auto q : queries) {
      auto p = upper_bound(nums.begin(), nums.end(), q) - nums.begin();

      long long sum1 = q * p - presum[p];
      long long sum2 = (presum.back() - presum[p]) - q * (n - p);

      ans.push_back(sum1 + sum2);
    }

    return ans;
  }
};
// Runtime 265 ms
// Memory 81.1 MB
