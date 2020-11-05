class Solution {
  unordered_map<int, vector<int>> mp;

 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    for (auto& e : edges) {
      mp[e[0]].push_back(e[1]);
      mp[e[1]].push_back(e[0]);
    }

    vector<int> ans;
    int minh = INT_MAX;

    for (int i = 0, h = INT_MAX; i < n; ++i) {
      h = dfs(i, {i});

      if (h < minh) {
        minh = h;
        ans.clear();
        ans.push_back(i);
      } else if (h == minh) {
        ans.push_back(i);
      }
    }

    return ans;
  }

  int dfs(int root, unordered_set<int> visited) {
    int h = 0;

    for (auto r : mp[root]) {
      if (visited.count(r) == 0) {
        visited.insert(r);
        h = max(h, dfs(r, visited) + 1);
        visited.erase(r);
      }
    }

    return h;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
      return {0};
    }

    vector<vector<int>> g(n);
    vector<int> d(n);

    for (int i = 0; i < edges.size(); ++i) {
      auto& e = edges[i];

      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);

      ++d[e[0]];
      ++d[e[1]];
    }

    queue<int> q;

    for (int i = 0; i < n; ++i) {
      if (d[i] == 1) {
        q.push(i);
      }
    }

    vector<int> ans;

    while (!q.empty()) {
      ans.clear();

      int cnt = q.size();

      while (cnt-- > 0) {
        auto v = q.front();
        q.pop();

        ans.push_back(v);

        for (auto vv : g[v]) {
          if (--d[vv] == 1) {
            q.push(vv);
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 116 ms, faster than 94.09%
// Memory Usage: 27.6 MB, less than 5.91%