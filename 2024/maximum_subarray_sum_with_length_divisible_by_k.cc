class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> presum(n + 1);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        long long ans = LLONG_MIN;
        for (int p = 0; p < k; ++p) {
            long long sum = 0;
            for (int i = p; i + k <= n; i += k) {
                long long cur = presum[i + k] - presum[i];
                sum = max(cur, sum + cur);
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
// 7 ms
// 171.39 MB
