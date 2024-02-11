class Solution {
 public:
  int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
    unordered_map<int, vector<int>> g;
    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    int ans = 0;

    function<int(int, int, int&)> dfs = [&](int root, int parent,
                                            int& invalid) -> int {
      int ret = 1;
      cout << "root: " << root << ", parent: " << parent << endl;
      int inv = 0;
      int inv2 = 0;
      for (auto child : g[root]) {
        if (child != parent) {
          int cnt = dfs(child, root, inv);
          inv2 |= inv;
          if (colors[child] == colors[root]) {
            ret += cnt;
          } else {
            inv2 = 1;
          }
        }
      }

      if (!inv2) {
        ans = max(ans, ret);
      } else {
        ans = max(ans, 1);
      }

      invalid = inv2;

      return ret;
    };

    int invalid = 0;
    dfs(0, -1, invalid);

    return ans;
  }
};
// 644 ms
// 226.82 MB