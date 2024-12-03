class Solution {
    void create(unordered_map<int, vector<int>>& g, vector<vector<int>>& edges) {
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
    }

    int dfs(unordered_map<int, vector<int>>& g, int parent, int node, int k) {
        if (k <= 0) {
            return k == 0;
        }

        int ret = 1;
        for (auto neighbor : g[node]) {
            if (neighbor != parent) {
                ret += dfs(g, node, neighbor, k - 1);
            }
        }

        return ret;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int, vector<int>> g1;
        unordered_map<int, vector<int>> g2;

        create(g1, edges1);
        create(g2, edges2);

        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        int max_cnt = 0;
        for (int i = 0; i < m; ++i) {
            max_cnt = max(max_cnt, dfs(g2, -1, i, k - 1));
        }

        vector<int> ans(n, max_cnt);
        for (int i = 0; i < n; ++i) {
            ans[i] += dfs(g1, -1, i, k);
        }

        return ans;
    }
};
// 211 ms
// 62.60 MB

