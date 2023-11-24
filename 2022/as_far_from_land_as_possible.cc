class Solution {
 public:
  int maxDistance(vector<vector<int>>& grid) {
    const int n = grid.size();

    vector<vector<int>> land, water;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          water.push_back({i, j});
        } else {
          land.push_back({i, j});
        }
      }
    }

    if (land.empty() || water.empty()) {
      return -1;
    }

    int ans = 0;

    for (int i = 0; i < water.size(); ++i) {
      const auto& w = water[i];
      int dis = INT_MAX;

      for (int j = 0; j < land.size(); ++j) {
        const auto& l = land[j];

        dis = min(dis, abs(l[0] - w[0]) + abs(l[1] - w[1]));
      }

      ans = max(ans, dis);
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxDistance(vector<vector<int>>& grid) {
    const int n = grid.size();

    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          q.push({i, j});
        }
      }
    }

    if (q.size() == n * n) {
      return -1;
    }

    int ans = 0;

    int dirs[] = {0, -1, 0, 1, 0};

    while (!q.empty()) {
      ++ans;

      int cnt = q.size();

      while (cnt-- > 0) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
          int dx = i + dirs[k];
          int dy = j + dirs[k + 1];

          if (dx < 0 || dy < 0 || dx >= n || dy >= n || grid[dx][dy] == 1) {
            continue;
          }
          grid[dx][dy] = 1;

          q.push({dx, dy});
        }
      }
    }

    return ans - 1;
  }
};
// Runtime: 67 ms, faster than 81.49%
// Memory Usage: 19.8 MB, less than 63.02%
// 2022.4.6 at 奥盛大厦