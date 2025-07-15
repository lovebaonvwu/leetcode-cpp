class Solution
{
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {

        int n = edges.size() + 1;

        vector<vector<pair<int, int>>> tree(n);
        for (auto &e : edges)
        {
            tree[e[0]].push_back({e[1], e[2]});
            tree[e[1]].push_back({e[0], e[2]});
        }

        function<int(int, int, int)> dfs = [&](int node, int parent, int dist) -> int
        {
            int cnt = dist % signalSpeed == 0;
            for (auto [child, w] : tree[node])
            {
                if (child != parent)
                {
                    cnt += dfs(child, node, dist + w);
                }
            }

            return cnt;
        };

        vector<int> ans;

        for (int i = 0; i < n; ++i)
        {
            int pairs = 0;
            int total = 0;

            for (auto &[child, w] : tree[i])
            {
                int cnt = dfs(child, i, w);
                pairs += total * cnt;
                total += cnt;
            }

            ans.push_back(pairs);
        }

        return ans;
    }
};
// Time: O(n^2)
// Space: O(n)