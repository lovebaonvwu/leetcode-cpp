class Solution {
 public:
  int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<int> q;
    for (int i = 0; i < m; ++i) {
      q.push(i);
    }

    int j = 0;

    while (!q.empty()) {
      int cnt = q.size();
      vector<bool> visited(m);

      while (cnt-- > 0) {
        int i = q.front();
        q.pop();

        for (int k = -1; k < 2; ++k) {
          if (i + k >= 0 && i + k < m && j + 1 < n) {
            if (!visited[i + k] && grid[i + k][j + 1] > grid[i][j]) {
              visited[i + k] = true;
              q.push(i + k);
            }
          }
        }
      }

      ++j;
    }

    return j - 1;
  }
};
// Runtime 218 ms
// Memory 63.6 MB