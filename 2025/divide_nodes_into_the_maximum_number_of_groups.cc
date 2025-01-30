class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        unordered_map<int, int> group;

        for (int i = 1; i <= n; ++i) {
            queue<int> q;
            q.push(i);
            vector<int> visited(n + 1);
            visited[i] = 1;
            int gId = INT_MAX;
            int level = 0;

            while (!q.empty()) {
                auto cnt = q.size();
                ++level;

                while (cnt-- > 0) {
                    auto node = q.front();
                    q.pop();

                    gId = min(gId, node);

                    for (auto neighbor : g[node]) {
                        if (visited[neighbor] == level) {
                            return -1;
                        }

                        if (visited[neighbor] == 0) {
                            visited[neighbor] = level + 1;
                            q.push({neighbor});
                        }
                    }
                }
            }

            group[gId] = max(group[gId], level);
        }

        int ans = 0;

        for (auto [_, cnt] : group) {
            ans += cnt;
        }

        return ans;
    }
};
// 144 ms
// 53.59 MB