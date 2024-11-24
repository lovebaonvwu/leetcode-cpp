class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();
        vector<int> presum(n + 1);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        for (int k = l; k <= r; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                ans = min(ans, presum[i + k] - presum[i] > 0 ? presum[i + k] - presum[i] : INT_MAX);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
// 0 ms
// 29.08 MB
