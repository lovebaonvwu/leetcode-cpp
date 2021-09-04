class Solution {
  int N;
  vector<vector<int>> g;
  vector<int> count;
  vector<int> ans;

 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    N = n;
    g.resize(n);

    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    count.resize(n);
    ans.resize(n);

    dfs(0, -1);
    dfs2(0, -1);

    return ans;
  }

  void dfs(int root, int parent) {
    for (auto child : g[root]) {
      if (child != parent) {
        dfs(child, root);
        count[root] += count[child];
        ans[root] += ans[child] + count[child];
      }
    }

    count[root] += 1;
  }

  void dfs2(int root, int parent) {
    for (auto child : g[root]) {
      if (child != parent) {
        ans[child] = ans[root] - count[child] + N - count[child];
        dfs2(child, root);
      }
    }
  }
};
// Runtime: 549 ms, faster than 5.18%
// Memory Usage: 87.4 MB, less than 46.02%
// 2021.9.4 at 茗筑美嘉