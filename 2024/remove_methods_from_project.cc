class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> g;
        for (auto& i : invocations) {
            g[i[0]].push_back(i[1]);
        }

        vector<bool> visited(n);
        function<void(int)> dfs = [&](int cur) -> void {
            for (auto next : g[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    dfs(next);
                }
            }
        };

        visited[k] = true;
        dfs(k);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                for (auto next : g[i]) {
                    if (visited[next]) {
                        vector<int> ans(n);
                        iota(begin(ans), end(ans), 0);
                        return ans;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
// 1491 ms
// 379.12 MB

