class Solution
{
public:
    vector<int> findCoins(vector<int> &numWays)
    {
        int n = numWays.size();

        vector<int> dp(n + 1);
        dp[0] = 1;

        vector<int> ans;
        for (int c = 1; c <= n; ++c)
        {
            if (dp[c] == numWays[c - 1])
            {
                continue;
            }

            ans.push_back(c);
            for (int i = c; i <= n; ++i)
            {
                dp[i] += dp[i - c];
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (dp[i] != numWays[i - 1])
            {
                return {};
            }
        }

        return ans;
    }
};
// Time: O(n^2)
// Space: O(n)