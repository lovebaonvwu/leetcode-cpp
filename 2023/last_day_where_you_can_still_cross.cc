class DisjointSet {
 public:
  DisjointSet(int n) : size(n) {
    parents.resize(size);
    iota(parents.begin(), parents.end(), 0);
    ranks.resize(size, 0);
  }

  int Find(int x) {
    if (parents[x] != x) {
      parents[x] = Find(parents[x]);
    }

    return parents[x];
  }

  void Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);

    if (px == py) {
      return;
    }

    if (ranks[px] <= ranks[py]) {
      parents[px] = py;
    } else {
      parents[py] = px;
    }
  }

 private:
  vector<int> parents;
  vector<int> ranks;
  int size;
};

class Solution {
 public:
  int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    vector<vector<int>> g(row, vector<int>(col, 1));
    DisjointSet ds(row * col + 2);

    for (int j = 0; j < col; ++j) {
      ds.Union(j, row * col);
      ds.Union((row - 1) * col + j, row * col + 1);
    }

    int dirs[] = {1, 0, -1, 0, 1};
    for (int i = cells.size() - 1; i >= 0; --i) {
      int y = cells[i][0] - 1, x = cells[i][1] - 1;
      g[y][x] = 0;

      for (int k = 0; k < 4; ++k) {
        int dy = y + dirs[k];
        int dx = x + dirs[k + 1];

        if (dy < 0 || dy == row || dx < 0 || dx == col) {
          continue;
        }

        if (g[dy][dx] == 1) {
          continue;
        }

        int a = y * col + x, b = dy * col + dx;
        ds.Union(a, b);

        if (ds.Find(row * col) == ds.Find(row * col + 1)) {
          return i;
        }
      }
    }

    return 0;
  }
};
// Runtime 373 ms
// Memory 107.7 MB