class Solution {
 public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    set<int> sums;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>& g = grid;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0;; ++k) {
          if (i + 2 * k >= m || j + k >= n || j - k < 0) {
            break;
          }

          if (k == 0) {
            sums.insert(g[i][j]);
            if (sums.size() > 3) {
              sums.erase(sums.begin());
            }
            continue;
          }

          int sum = 0;
          pair<int, int> a, b, c, d;
          a = {i, j};
          b = {i + k, j + k};
          c = {i + 2 * k, j};
          d = {i + k, j - k};

          for (int l = 0; l < k; ++l) {
            sum += g[a.first++][a.second++];
            sum += g[b.first++][b.second--];
            sum += g[c.first--][c.second--];
            sum += g[d.first--][d.second++];
          }

          sums.insert(sum);
          if (sums.size() > 3) {
            sums.erase(sums.begin());
          }
        }
      }
    }

    return vector<int>(sums.rbegin(), sums.rend());
  }
};
// Runtime 802 ms
// Memory 61.6 MB
// 2022.11.17 at 奥盛大厦