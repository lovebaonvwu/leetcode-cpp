class Solution
{
    int calc(int a, int b, int c)
    {
        return max(a, max(b, c)) - min(a, min(b, c));
    }

public:
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> g;

        for (auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int total = 0;
        for (int x : nums)
        {
            total ^= x;
        }

        int ans = INT_MAX;

        function<int(int, int, int, int)> dfs2 = [&](int node, int parent, int p1, int ancestor) -> int
        {
            int p2 = nums[node];

            for (auto child : g[node])
            {
                if (child != parent)
                {
                    p2 ^= dfs2(child, node, p1, ancestor);
                }
            }

            if (parent == ancestor)
            {
                return p2;
            }

            ans = min(ans, calc(p1, p2, total ^ p1 ^ p2));

            return p2;
        };

        function<int(int, int)> dfs = [&](int node, int parent) -> int
        {
            int p1 = nums[node];

            for (auto child : g[node])
            {
                if (child != parent)
                {
                    p1 ^= dfs(child, node);
                }
            }

            for (auto child : g[node])
            {
                if (child == parent)
                {
                    dfs2(child, node, p1, node);
                }
            }

            return p1;
        };

        dfs(0, -1);

        return ans;
    }
};
// Time: O(n*m)
// Space: O(n)