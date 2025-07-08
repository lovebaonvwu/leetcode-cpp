class Solution
{
public:
    int minTime(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<array<int, 3>>> g;

        for (auto &e : edges)
        {
            g[e[0]].push_back({e[1], e[2], e[3]});
        }

        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty())
        {
            auto [cur_time, node] = pq.top();
            pq.pop();

            if (node == n - 1)
            {
                return cur_time;
            }

            for (auto [next, start, end] : g[node])
            {
                if (cur_time <= end && max(cur_time, start) + 1 <= dist[next])
                {
                    dist[next] = max(cur_time, start) + 1;
                    pq.push({max(cur_time, start) + 1, next});
                }
            }
        }

        return -1;
    }
};
// Time: O(E log V)
// Space: O(V + E), where V is the number of vertices and E is the number of edges