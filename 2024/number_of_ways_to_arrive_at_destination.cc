class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& r : roads) {
            g[r[0]].push_back({r[1], r[2]});
            g[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<int> ways(n);
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        int mod = 1e9 + 7;
        while (!pq.empty()) {
            auto [curtime, node] = pq.top();
            pq.pop();

            for (auto& [next, time] : g[node]) {
                if (curtime + time < dist[next]) {
                    dist[next] = curtime + time;
                    ways[next] = ways[node];
                    pq.push({curtime + time, next});
                } else if (curtime + time == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
// 7 ms
// 34.97 MB
