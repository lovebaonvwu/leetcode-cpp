class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans = 0;
        function<long long (int, int)> dfs = [&](int node, int parent) -> long long {
            long long sum = values[node];
            for (auto child : g[node]) {
                if (child != parent) {
                    sum += dfs(child, node);
                }
            }

            if (sum % k == 0) {
                ++ans;
                return 0;
            } else {
                return sum;
            }
        };

        dfs(0, -1);
        return ans;
    }
};
// 236 ms
// 178.06 MB
