class Solution {
  vector<vector<bool>> row;
  vector<vector<bool>> col;
  vector<vector<bool>> box;

  int m;
  int n;

 public:
  void solveSudoku(vector<vector<char>>& board) {
    row = vector<vector<bool>>(9, vector<bool>(10));
    col = vector<vector<bool>>(9, vector<bool>(10));
    box = vector<vector<bool>>(9, vector<bool>(10));

    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] != '.') {
          int d = board[i][j] - '0';
          row[i][d] = true;
          col[j][d] = true;
          box[i / 3 * 3 + j / 3][d] = true;
        }
      }
    }

    dfs(board, 0, 0);
  }

  bool dfs(vector<vector<char>>& board, int i, int j) {
    if (i == 9) {
      return true;
    }

    if (j == 9) {
      return dfs(board, i + 1, 0);
    }

    if (board[i][j] != '.') {
      return dfs(board, i, j + 1);
    }

    for (int k = 1; k <= 9; ++k) {
      if (!row[i][k] && !col[j][k] && !box[i / 3 * 3 + j / 3][k]) {
        row[i][k] = true;
        col[j][k] = true;
        box[i / 3 * 3 + j / 3][k] = true;

        board[i][j] = k + '0';

        if (dfs(board, i, j + 1)) {
          return true;
        }

        row[i][k] = false;
        col[j][k] = false;
        box[i / 3 * 3 + j / 3][k] = false;
        board[i][j] = '.';
      }
    }

    return false;
  }
};
// Runtime: 12 ms, faster than 87.85%
// Memory Usage: 6.6 MB, less than 25.06%
// 2021.8.21 at 茗筑美嘉