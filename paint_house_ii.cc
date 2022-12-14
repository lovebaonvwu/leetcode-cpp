class Solution {
public:
    int minCostII(vector<vector<int>>& costs) 
    {
        int m = costs.size();
        int n = costs[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = costs[0][j];
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int cost = INT_MAX;
                for (int k = 1; k < n; ++k)
                {
                    cost = min(cost, dp[i - 1][(j + k) % n]);
                }
                dp[i][j] = costs[i][j] + cost;
            }
        }

        return *min_element(begin(dp[m - 1]), end(dp[m - 1]));
    }
};
// Runtime 21 ms
// Memory 11.8 MB
// 2022.12.14 at 奥盛大厦
