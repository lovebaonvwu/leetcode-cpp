class Solution
{
    int ans = 0;

public:
    int minIncrease(int n, vector<vector<int>> &edges, vector<int> &cost)
    {
        unordered_map<int, vector<int>> tree;
        for (auto &e : edges)
        {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<long long> new_cost;
        for (auto c : cost)
        {
            new_cost.push_back(c);
        }

        function<long long(int, int)> dfs = [&](int node, int parent) -> long long
        {
            long long max_child = 0;
            for (auto child : tree[node])
            {
                if (child == parent)
                {
                    continue;
                }

                dfs(child, node);

                max_child = max(max_child, new_cost[child]);
            }

            for (auto child : tree[node])
            {
                if (child == parent)
                {
                    continue;
                }

                if (new_cost[child] < max_child)
                {
                    ++ans;
                }
            }

            new_cost[node] += max_child;

            return new_cost[node] + max_child;
        };

        dfs(0, -1);

        return ans;
    }
};
// Time: O(n)
// Space: O(n)