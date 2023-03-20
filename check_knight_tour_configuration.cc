class Solution {
  bool validMove(int i, int j, int x, int y) {
    return (i + 2 == x && j + 1 == y) || (i + 2 == x && j - 1 == y) ||
           (i - 2 == x && j + 1 == y) || (i - 2 == x && j - 1 == y) ||
           (i + 1 == x && j + 2 == y) || (i + 1 == x && j - 2 == y) ||
           (i - 1 == x && j + 2 == y) || (i - 1 == x && j - 2 == y);
  }

 public:
  bool checkValidGrid(vector<vector<int>>& grid) {
    if (grid[0][0] != 0) {
      return false;
    }

    unordered_map<int, pair<int, int>> mp;

    int n = grid.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mp[grid[i][j]] = {i, j};
      }
    }

    int cur = 0;
    int i = 0, j = 0;
    while (cur < n * n - 1) {
      int next = cur + 1;
      auto [x, y] = mp[next];

      if (!validMove(i, j, x, y)) {
        return false;
      }

      ++cur;
      i = x;
      j = y;
    }

    return true;
  }
};
// Runtime 8 ms
// Memory 28.1 MB