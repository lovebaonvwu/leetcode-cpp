class Solution {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    unordered_map<int, vector<int>> g;
    unordered_set<int> visited;

    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    int ans = dfs(g, hasApple, visited, 0);

    return ans > 0 ? ans - 2 : 0;
  }

  int dfs(unordered_map<int, vector<int>>& g,
          vector<bool>& hasApple,
          unordered_set<int>& visited,
          int root) {
    if (visited.count(root)) {
      return 0;
    }

    visited.insert(root);

    if (g.find(root) == g.end()) {
      return hasApple[root] ? 2 : 0;
    }

    int res = 0;
    for (auto v : g[root]) {
      res += dfs(g, hasApple, visited, v);
    }

    if (hasApple[root] || res > 0) {
      res += 2;
    }

    return res;
  }
};
// Runtime: 460 ms, faster than 41.18%
// Memory Usage: 76.9 MB, less than 17.02%