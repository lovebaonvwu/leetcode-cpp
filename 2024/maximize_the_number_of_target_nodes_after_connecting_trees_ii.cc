class Solution {

    void build(vector<vector<int>>& edges, unordered_map<int, vector<int>>& g) {
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
    }

    int dfs(unordered_map<int, vector<int>>& g, vector<bool>& parity, int parent, int node, bool even) {
        int ret = even;
        parity[node] = even;

        for (auto neighbor : g[node]) {
            if (neighbor != parent) {
                ret += dfs(g, parity, node, neighbor, !even);
            }
        }

        return ret;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        unordered_map<int, vector<int>> g1;
        unordered_map<int, vector<int>> g2;

        build(edges1, g1);
        build(edges2, g2);

        vector<bool> parity1(n);
        vector<bool> parity2(m);
        int even1 = dfs(g1, parity1, -1, 0, true);
        int even2 = dfs(g2, parity2, -1, 0, true);
        int odd1 = n - even1;
        int odd2 = m - even2;

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = (parity1[i] ? even1 : odd1) + max(odd2, even2);
        }

        return ans;
    }
};
// 516 ms
// 389.80 MB
