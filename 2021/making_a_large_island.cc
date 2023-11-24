class Solution {
  vector<vector<int>>* g;
  int n;
  int id;

 public:
  int largestIsland(vector<vector<int>>& grid) {
    n = grid.size();
    g = &grid;

    unordered_map<int, int> mp;
    id = 1;

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ++id;
          mp[id] = dfs(i, j);
          ans = max(ans, mp[id]);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int area = 1;
        if (grid[i][j] == 0) {
          for (auto id : set<int>{getId(i + 1, j), getId(i - 1, j),
                                  getId(i, j + 1), getId(i, j - 1)}) {
            area += mp[id];
          }
        }

        ans = max(ans, area);
      }
    }

    return ans;
  }

 private:
  int dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n || (*g)[x][y] != 1) {
      return 0;
    }

    (*g)[x][y] = id;

    return 1 + dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1);
  }

  int getId(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
      return 0;
    }

    return (*g)[x][y];
  }
};
// Runtime: 676 ms, faster than 52.37%
// Memory Usage: 170.7 MB, less than 52.92%
// 2021.8.1 at 茗筑美嘉