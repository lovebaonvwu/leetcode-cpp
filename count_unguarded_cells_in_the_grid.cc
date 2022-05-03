class Solution {
 public:
  int countUnguarded(int m,
                     int n,
                     vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    vector<vector<int>> visited(m, vector<int>(n));

    for (auto& w : walls) {
      visited[w[0]][w[1]] = 2;
    }

    queue<pair<int, int>> q;
    for (auto& g : guards) {
      q.push({g[0], g[1]});
      visited[g[0]][g[1]] = 2;
    }

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      for (int k = i + 1; k < m; ++k) {
        if (visited[k][j] == 2) {
          break;
        }

        visited[k][j] = 1;
      }

      for (int k = i - 1; k >= 0; --k) {
        if (visited[k][j] == 2) {
          break;
        }

        visited[k][j] = 1;
      }

      for (int k = j + 1; k < n; ++k) {
        if (visited[i][k] == 2) {
          break;
        }

        visited[i][k] = 1;
      }

      for (int k = j - 1; k >= 0; --k) {
        if (visited[i][k] == 2) {
          break;
        }

        visited[i][k] = 1;
      }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans += visited[i][j] == 0;
      }
    }

    return ans;
  }
};
// Runtime: 720 ms, faster than 61.53%
// Memory Usage: 157.1 MB, less than 50.02%
// 2022.5.3 at 茗筑美嘉