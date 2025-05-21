class Solution
{
    using LL = long long;
    constexpr static LL invalid = -1e18;

    LL dfs(int node, int parent, LL mul, int dist, int k, unordered_map<int, vector<int>> &g, vector<int> &nums, vector<vector<vector<LL>>> &cached)
    {
        dist = min(dist, k);

        if (cached[node][mul + 1][dist] != invalid)
        {
            return cached[node][mul + 1][dist];
        }

        LL ret = invalid;
        if (dist == 0)
        {
            LL val0 = nums[node] * mul;
            for (auto child : g[node])
            {
                if (child != parent)
                {
                    val0 += dfs(child, node, mul, 0, k, g, nums, cached);
                }
            }

            LL val1 = nums[node] * mul * -1;
            for (auto child : g[node])
            {
                if (child != parent)
                {
                    val1 += dfs(child, node, mul * -1, 1, k, g, nums, cached);
                }
            }

            ret = max(val0, val1);
        }
        else if (dist < k)
        {
            LL val0 = nums[node] * mul;
            for (auto child : g[node])
            {
                if (child != parent)
                {
                    val0 += dfs(child, node, mul, dist + 1, k, g, nums, cached);
                }
            }

            ret = val0;
        }
        else if (dist >= k)
        {
            LL val0 = nums[node] * mul;
            for (auto child : g[node])
            {
                if (child != parent)
                {
                    val0 += dfs(child, node, mul, dist + 1, k, g, nums, cached);
                }
            }

            LL val1 = nums[node] * mul * -1;
            for (auto child : g[node])
            {
                if (child != parent)
                {
                    val1 += dfs(child, node, mul * -1, 1, k, g, nums, cached);
                }
            }

            ret = max(val0, val1);
        }

        return cached[node][mul + 1][dist] = ret;
    };

public:
    long long subtreeInversionSum(vector<vector<int>> &edges, vector<int> &nums, int k)
    {
        unordered_map<int, vector<int>> g;
        for (auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int n = nums.size();

        vector<vector<vector<LL>>> cached(n, vector<vector<LL>>(3, vector<LL>(k + 1, invalid)));

        return dfs(0, -1, 1, 0, k, g, nums, cached);
    }
};
// Time: O(n * k * 2)
// Space: O(n * k * 2)