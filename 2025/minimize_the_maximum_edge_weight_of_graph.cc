class Solution {
    public:
        int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
            vector<vector<pair<int, int>>> g(n);
    
            int maxWeight = 0;
            for (auto& e : edges) {
                g[e[1]].push_back({e[0], e[2]});
                maxWeight = max(maxWeight, e[2]);
            }
    
            function<int(int, int, vector<bool>&)> dfs = [&](int node, int md, vector<bool>& visited) -> int {
                int ret = 1;
                visited[node] = true;
                for (auto& [neighbor, weight] : g[node]) {
                    if (!visited[neighbor] && weight <= md) {
                        ret += dfs(neighbor, md, visited);
                    }
                }
    
                return ret;
            };
    
            int lo = 0;
            int hi = maxWeight + 1;
    
            while (lo < hi) {
                int md = (lo + hi) / 2;
                vector<bool> visited(n);
                if (dfs(0, md, visited) == n) {
                    hi = md;
                } else {
                    lo = md + 1;
                }
            }
    
            return lo == maxWeight + 1 ? -1 : lo;
        }
    };
    // 259 ms
    // 262.97 MB
