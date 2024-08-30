class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> g(n);
        const int INF = 2e9;
        for (auto& e : edges) {
            if (e[2] != -1) {
                g[e[0]].push_back({e[1], e[2]});
                g[e[1]].push_back({e[0], e[2]});
            }
        }

        function<int()> dijkstra = [&]() -> int {
            vector<int> dist(n, INT_MAX);
            dist[source] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.push({0, source});

            while (!pq.empty()) {
                auto [curDist, curNode] = pq.top();
                pq.pop();

                if (curNode == destination) {
                    return curDist;
                }

                for (auto& [nextNode, d] : g[curNode]) {
                    if (curDist + d < dist[nextNode]) {
                        dist[nextNode] = curDist + d;
                        pq.push({curDist + d, nextNode});
                    }
                }
            }

            return dist[destination];
        };

        int dist = dijkstra();
        if (dist < target) {
            return vector<vector<int>>();
        }

        bool matchesTarget = dist == target;
        for (auto& e : edges) {
            if (e[2] != -1) {
                continue;
            }

            e[2] = matchesTarget ? INF : 1;
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});

            if (!matchesTarget) {
                int dist = dijkstra();

                if (dist <= target) {
                    e[2] += target - dist;
                    matchesTarget = true;
                }
            }
        }

        return matchesTarget ? edges : vector<vector<int>>();
    }
};
// 532 ms
// 243.75 MB
