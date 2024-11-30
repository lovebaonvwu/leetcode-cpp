class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> in;
        unordered_map<int, int> out;
        unordered_map<int, vector<int>> g;

        for (auto& pair : pairs) {
            int start = pair[0];
            int end = pair[1];

            ++in[end];
            ++out[start];
            g[start].push_back(end);
        }

        int start = pairs[0][0];
        for (auto [node, _] : g) {
            if (out[node] == in[node] + 1) {
                start = node;
                break;
            }
        }

        vector<int> path;
        function<void(int)> dfs = [&](int node) -> void {
            while (!g[node].empty()) {
                int next = g[node].back();
                g[node].pop_back();
                dfs(next);
            }

            path.push_back(node);
        };

        dfs(start);
        
        vector<vector<int>> ans;
        for (int i = path.size() - 1; i > 0; --i) {
            ans.push_back({path[i], path[i - 1]});
        }

        return ans;
    }
};
// 1674 ms
// 296.30 MB
