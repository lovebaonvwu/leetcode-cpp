class Solution {
 public:
  vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<pair<int, int>>> g;
    for (auto& e : edges) {
      int u = e[0];
      int v = e[1];

      g[u].push_back({v, 1});
      g[v].push_back({u, -1});
    }

    function<int(int, int)> count = [&](int root, int parent) -> int {
      int ret = 0;
      for (auto& [child, dir] : g[root]) {
        if (child == parent)
          continue;
        if (dir == 1) {
          ret += count(child, root);
        } else {
          ret += count(child, root) + 1;
        }
      }

      return ret;
    };

    int cnt = count(0, -1);
    vector<int> ans(n);

    function<void(int, int, int)> dfs = [&](int root, int parent,
                                            int c) -> void {
      ans[root] = c;

      for (auto& [child, dir] : g[root]) {
        if (child == parent)
          continue;
        if (dir == 1) {
          dfs(child, root, c + 1);
        } else {
          dfs(child, root, c - 1);
        }
      }
    };

    dfs(0, -1, cnt);

    return ans;
  }
};
// 1328ms
// 232.45MB