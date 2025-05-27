class Solution
{
public:
    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> tree;
        for (auto &e : edges)
        {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        function<int(int, int)> getHeight = [&](int node, int parent) -> int
        {
            int height = 0;

            for (auto child : tree[node])
            {
                if (child != parent)
                {
                    height = max(height, 1 + getHeight(child, node));
                }
            }

            return height;
        };

        int maxDepth = getHeight(1, -1);

        vector<vector<int>> dp(maxDepth + 1, vector<int>(2));
        dp[1][0] = 1;
        dp[1][1] = 1;

        int mod = 1e9 + 7;
        for (int i = 2; i <= maxDepth; ++i)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        }

        return dp[maxDepth][1];
    }
};

// Time: O(n)
// Space: O(n)