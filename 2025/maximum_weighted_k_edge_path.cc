class Solution
{
public:
    int maxWeight(int n, vector<vector<int>> &edges, int k, int t)
    {

        if (k == 0)
        {
            return 0;
        }

        unordered_map<int, vector<pair<int, int>>> g;
        vector<int> indegree(n);
        for (auto &e : edges)
        {
            g[e[0]].push_back({e[1], e[2]});
            ++indegree[e[1]];
        }

        vector<int> roots;
        for (int i = 0; i < n; ++i)
        {
            if (indegree[i] == 0)
            {
                roots.push_back(i);
            }
        }

        int ans = -1;

        function<void(int, int, deque<int>)> dfs = [&](int node, int sum, deque<int> path) -> void
        {
            if (path.size() == k && sum < t)
            {
                ans = max(ans, sum);
            }

            for (auto &[next, w] : g[node])
            {
                if (path.size() == k)
                {
                    sum -= path.front();
                    path.pop_front();
                }

                sum += w;
                path.push_back(w);

                dfs(next, sum, path);

                path.pop_back();
                sum -= w;
            }
        };

        for (auto root : roots)
        {
            deque<int> q;
            dfs(root, 0, q);
        }

        return ans;
    }
};
// Time: O(N * D^k)

class Solution
{

    int dfs(unordered_map<int, vector<pair<int, int>>> &g, vector<vector<unordered_map<int, int>>> &cached, int node, int k, int sum, int t)
    {
        if (k == 0)
        {
            return sum < t ? sum : -1;
        }

        if (cached[node][k].count(sum))
        {
            return cached[node][k][sum];
        }

        int ret = -1;

        for (auto &[next, w] : g[node])
        {
            if (sum + w >= t)
            {
                continue;
            }

            ret = max(ret, dfs(g, cached, next, k - 1, sum + w, t));
        }

        return cached[node][k][sum] = ret;
    };

public:
    int maxWeight(int n, vector<vector<int>> &edges, int k, int t)
    {

        unordered_map<int, vector<pair<int, int>>> g;
        for (auto &e : edges)
        {
            g[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<unordered_map<int, int>>> cached(n, vector<unordered_map<int, int>>(k + 1));

        int ans = -1;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, dfs(g, cached, i, k, 0, t));
        }

        return ans;
    }
};
// Time: O(n * k * sum)
// Space: O(n * k)