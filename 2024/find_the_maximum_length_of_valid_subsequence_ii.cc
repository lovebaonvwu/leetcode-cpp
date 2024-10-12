class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k));

        int ans = 0;
        for (auto n : nums) {
            int cur = n % k;
            for (int mod = 0; mod < k; ++mod) {
                dp[mod][cur] = max(dp[mod][cur], dp[mod][(mod + k - cur) % k] + 1);
                ans = max(ans, dp[mod][cur]);
            }
        }

        return ans;
    }
};
// 88 ms
// 129.4 MB