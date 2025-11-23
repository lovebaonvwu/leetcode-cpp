class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][(nums[i - 1] + 0) % 3] + nums[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][(nums[i - 1] + 1) % 3] + nums[i - 1]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][(nums[i - 1] + 2) % 3] + nums[i - 1]);
        }

        return dp[n][0];
    }
};
// Time: O(n)
// Space: O(n)