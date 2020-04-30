class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    dfs(graph, {0}, 0);

    return ans;
  }

  void dfs(vector<vector<int>>& g, vector<int> path, int i) {
    if (i == g.size() - 1) {
      ans.push_back(path);
      return;
    }

    for (int p : g[i]) {
      path.push_back(p);
      dfs(g, path, p);
      path.pop_back();
    }
  }
};
// Runtime: 32 ms, faster than 99.48%
// Memory Usage: 15.5 MB, less than 60.00%