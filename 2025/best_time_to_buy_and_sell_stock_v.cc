class Solution
{
    using LL = long long;

public:
    long long maximumProfit(vector<int> &prices, int k)
    {
        int n = prices.size();

        LL minProfit = -1e14;

        vector<vector<vector<LL>>> cached(n + 1, vector<vector<LL>>(k + 1, vector<LL>(3, minProfit)));

        function<LL(int, int, int)> dfs = [&](int d, int t, int state) -> LL
        {
            if (d == n)
            {
                return state == 0 ? 0 : minProfit;
            }

            if (cached[d][t][state] != minProfit)
            {
                return cached[d][t][state];
            }

            LL ret = minProfit;

            ret = max(ret, dfs(d + 1, t, state));

            if (state == 0)
            {
                ret = max(ret, -prices[d] + dfs(d + 1, t, 1));
                ret = max(ret, prices[d] + dfs(d + 1, t, 2));
            }
            else if (t > 0)
            {
                if (state == 1)
                {
                    ret = max(ret, prices[d] + dfs(d + 1, t - 1, 0));
                }
                else
                {
                    ret = max(ret, -prices[d] + dfs(d + 1, t - 1, 0));
                }
            }

            return cached[d][t][state] = ret;
        };

        return dfs(0, k, 0);
    }
};
// Time: O(n * k)
// Space: O(n * k)