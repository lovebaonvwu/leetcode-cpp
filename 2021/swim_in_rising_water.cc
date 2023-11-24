class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<vector<bool>> visited(n, vector<bool>(n));

    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

    pq.push({grid[0][0], 0, 0});

    int dirs[5] = {0, -1, 0, 1, 0};
    int ans = 0;

    while (!pq.empty()) {
      int h = pq.top()[0];
      int x = pq.top()[1];
      int y = pq.top()[2];

      pq.pop();

      ans = max(ans, h);

      if (x == n - 1 && y == n - 1) {
        return ans;
      }

      for (int i = 0; i < 4; ++i) {
        int dx = x + dirs[i];
        int dy = y + dirs[i + 1];

        if (dx < 0 || dx >= n || dy < 0 || dy >= n || visited[dx][dy]) {
          continue;
        }

        pq.push({grid[dx][dy], dx, dy});

        visited[dx][dy] = true;
      }
    }

    return -1;
  }
};
// Runtime: 40 ms, faster than 30.84%
// Memory Usage: 10.2 MB, less than 45.02%