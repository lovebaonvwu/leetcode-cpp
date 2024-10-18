class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int dp[2001][51] = {0};
        int mod = 1e9 + 7;
        for (int j = 0; j <= nums[0]; ++j) {
            dp[0][j] = 1;
        }

        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= nums[i]; ++j) {
                for (int k = 0; k <= j; ++k) {
                    if (dp[i - 1][k] > 0 && (nums[i] - j) <= (nums[i - 1] - k)) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 51; ++i) {
            ans = (ans + dp[n - 1][i]) % mod;
        }
        return ans;
    }
};
// 71 ms
// 31.64 MB

