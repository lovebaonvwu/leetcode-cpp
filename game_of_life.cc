class Solution {
  int cntOne(vector<vector<int>>& b, int x, int y) {
    int cnt = 0;
    int m = b.size();
    int n = b[0].size();

    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (i == 0 && j == 0) {
          continue;
        }

        if (x + i < 0 || x + i >= m || y + j < 0 || y + j >= n) {
          continue;
        }

        cnt += b[x + i][y + j];
      }
    }

    return cnt;
  }

 public:
  void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();

    vector<vector<int>> tmp(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        tmp[i][j] = board[i][j];
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j]) {
          if (cntOne(tmp, i, j) < 2) {
            board[i][j] = 0;
          } else if (cntOne(tmp, i, j) > 3) {
            board[i][j] = 0;
          }
        } else if (cntOne(tmp, i, j) == 3) {
          board[i][j] = 1;
        }
      }
    }
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.5 MB, less than 18.85%

class Solution {
  int cntOne(vector<vector<int>>& b, int x, int y) {
    int cnt = 0;
    int m = b.size();
    int n = b[0].size();

    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (i == 0 && j == 0) {
          continue;
        }

        if (x + i < 0 || x + i >= m || y + j < 0 || y + j >= n) {
          continue;
        }

        cnt += b[x + i][y + j] & 1;
      }
    }

    return cnt;
  }

 public:
  void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j]) {
          if (cntOne(board, i, j) < 2) {
            board[i][j] = 1;
          } else if (cntOne(board, i, j) > 3) {
            board[i][j] = 1;
          } else {
            board[i][j] = 3;
          }
        } else if (cntOne(board, i, j) == 3) {
          board[i][j] = 2;
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        board[i][j] >>= 1;
      }
    }
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.3 MB, less than 88.65%