class Solution {
  vector<int> parent;

 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();

    parent.resize(n);

    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }

    int ans = n;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (isConnected[i][j]) {
          int x = find(i);
          int y = find(j);

          if (x != y) {
            parent[x] = y;

            --ans;
          }
        }
      }
    }

    return ans;
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }
};
// Runtime: 20 ms, faster than 89.42%
// Memory Usage: 13.7 MB, less than 64.74%
// 2021.10.8 at 奥盛大厦

class Solution {
  vector<int> visited;

 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();

    visited.resize(n);

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      if (visited[i]) {
        continue;
      }

      dfs(isConnected, i);

      ++ans;
    }

    return ans;
  }

  void dfs(vector<vector<int>>& isConnected, int i) {
    visited[i] = true;

    for (int j = 0; j < visited.size(); ++j) {
      if (!visited[j] && isConnected[i][j]) {
        dfs(isConnected, j);
      }
    }
  }
};
// Runtime: 20 ms, faster than 89.42%
// Memory Usage: 13.8 MB, less than 64.74%
// 2021.10.8 at 奥盛大厦