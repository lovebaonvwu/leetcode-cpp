class Solution 
{
public:
    int minCost(vector<vector<int>>& costs) 
    {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));

        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= 2; ++j)
            {
                dp[i][j] = costs[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
            }
        }

        return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};
// Runtime 12 ms
// Memory 10.2 MB
// 2022.12.14