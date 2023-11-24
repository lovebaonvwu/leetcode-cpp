class Solution {
  vector<pair<int, int>> moves{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

 public:
  void solve(vector<vector<char>>& board) {
    size_t m = board.size();
    if (m == 0) {
      return;
    }

    size_t n = board[0].size();

    for (int j = 0; j < n; ++j) {
      dfs(board, 0, j);
      dfs(board, m - 1, j);
    }

    for (int i = 0; i < m; ++i) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == 'T') {
          board[i][j] = 'O';
        }
      }
    }
  }

  void dfs(vector<vector<char>>& b, int x, int y) {
    if (x < 0 || x > b.size() - 1 || y < 0 || y > b[0].size() - 1) {
      return;
    }

    if (b[x][y] == 'O') {
      b[x][y] = 'T';

      for (auto [dx, dy] : moves) {
        dfs(b, x + dx, y + dy);
      }
    }
  }
};
// Runtime: 28 ms, faster than 84.23%
// Memory Usage: 10.1 MB, less than 83.86%