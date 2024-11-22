class Solution {
        void count(unordered_map<int, vector<int>>& g, vector<int>& ans, int node) {
            for (auto child : g[node]) {
                count(g, ans, child);
                ans[node] += ans[child];
            }
        };

        void dfs(vector<int> chars, unordered_map<int, vector<int>>& tree, vector<int>& changed, string& s, int node) {
            if (chars[s[node] - 'a'] != -1) {
                changed[node] = chars[s[node] - 'a'];
            }

            chars[s[node] - 'a'] = node;

            for (auto child : tree[node]) {
                dfs(chars, tree, changed, s, child);
            }
        };

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> changed = parent;
        vector<int> chars(26, -1);

        unordered_map<int, vector<int>> tree;
        for (int i = 0; i < n; ++i) {
            tree[parent[i]].push_back(i);
        }

        dfs(chars, tree, changed, s, 0);

        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; ++i) {
            g[changed[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        count(g, ans, 0);

        return ans;
    }
};
// 3030 ms
// 525.17 MB
