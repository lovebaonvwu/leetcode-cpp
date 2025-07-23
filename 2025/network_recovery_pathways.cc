class Solution
{
public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k)
    {
        int n = online.size();

        unordered_map<int, vector<pair<int, int>>> g;

        for (auto &e : edges)
        {
            g[e[0]].push_back({e[1], e[2]});
        }

        queue<array<int, 3>> q;
        q.push({0, 0, INT_MAX});

        int ans = -1;

        while (!q.empty())
        {
            auto [node, cost, min_edge] = q.front();
            q.pop();

            if (node == n - 1)
            {
                ans = max(ans, min_edge);
            }

            for (auto &[next, weight] : g[node])
            {
                if (!online[next])
                {
                    continue;
                }

                if (cost + weight > k)
                {
                    continue;
                }

                q.push({next, cost + weight, min(min_edge, weight)});
            }
        }

        return ans;
    }
};
// Memory Limit Exceeded
// Time: O(n + m)
// Space: O(n + m)

class Solution
{
public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k)
    {
        int n = online.size();

        int lo = -1;
        int hi = 1e9;

        while (lo < hi)
        {
            int md = (lo + hi + 1) / 2;

            unordered_map<int, vector<pair<int, int>>> g;
            for (auto &e : edges)
            {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if (online[u] && online[v] && w >= md)
                {
                    g[u].push_back({v, w});
                }
            }

            if (check(g, n) <= k)
            {
                lo = md;
            }
            else
            {
                hi = md - 1;
            }
        }

        return lo;
    }

    long long check(unordered_map<int, vector<pair<int, int>>> &g, int n)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        vector<long long> dist(n, LONG_MAX);

        while (!pq.empty())
        {
            auto [cur_dist, node] = pq.top();
            pq.pop();

            if (node == n - 1)
            {
                return cur_dist;
            }

            for (auto &[next, w] : g[node])
            {
                if (cur_dist + w < dist[next])
                {
                    dist[next] = cur_dist + w;
                    pq.push({dist[next], next});
                }
            }
        }

        return LONG_MAX;
    }
};
// Time: O((n + m) log n)
// Space: O(n + m)

class Solution
{
public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k)
    {
        int n = online.size();

        int lo = -1;
        int hi = 0;

        unordered_map<int, vector<pair<int, int>>> g;
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if (online[u] && online[v])
            {
                g[u].push_back({v, w});
                hi = max(hi, w);
            }
        }

        long long ans = -1;
        while (lo <= hi)
        {
            int md = (lo + hi) / 2;

            if (check(g, n, md) <= k)
            {
                lo = md + 1;
                ans = md;
            }
            else
            {
                hi = md - 1;
            }
        }

        return ans;
    }

    long long check(unordered_map<int, vector<pair<int, int>>> &g, int n, int md)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        vector<long long> dist(n, LONG_MAX);
        dist[0] = 0;

        while (!pq.empty())
        {
            auto [cur_dist, node] = pq.top();
            pq.pop();

            if (node == n - 1)
            {
                return cur_dist;
            }

            for (auto &[next, w] : g[node])
            {
                if (cur_dist + w < dist[next] && w >= md)
                {
                    dist[next] = cur_dist + w;
                    pq.push({dist[next], next});
                }
            }
        }

        return LONG_MAX;
    }
};
// Time: O((n + m) log n)
// Space: O(n + m)