class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    const int sz = 9;

    int row[sz][sz]{false};
    int col[sz][sz]{false};
    int sub[sz][sz]{false};

    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        if (isdigit(board[i][j])) {
          int val = board[i][j] - '0' - 1;

          if (row[i][val])
            return false;
          row[i][val] = true;

          if (col[j][val])
            return false;
          col[j][val] = true;

          int idx = i / 3 * 3 + j / 3;
          if (sub[idx][val])
            return false;
          sub[idx][val] = true;
        }
      }
    }

    return true;
  }
};
// Runtime: 12 ms, faster than 89.90%
// Memory Usage: 9.3 MB, less than 100.00%

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    const int sz = 9;

    for (int i = 0; i < sz; ++i) {
      vector<bool> tmp(sz + 1, false);
      for (int j = 0; j < sz; ++j) {
        if (isdigit(board[i][j]) && tmp[board[i][j] - '0']) {
          return false;
        } else if (isdigit(board[i][j])) {
          tmp[board[i][j] - '0'] = true;
        }
      }
    }

    for (int i = 0; i < sz; ++i) {
      vector<bool> tmp(sz + 1, false);
      for (int j = 0; j < sz; ++j) {
        if (isdigit(board[j][i]) && tmp[board[j][i] - '0']) {
          return false;
        } else if (isdigit(board[j][i])) {
          tmp[board[j][i] - '0'] = true;
        }
      }
    }

    for (int m = 0; m < 9; m += 3) {
      for (int n = 0; n < 9; n += 3) {
        vector<bool> tmp(sz + 1, false);
        for (int i = m; i < m + 3; ++i) {
          for (int j = n; j < n + 3; ++j) {
            if (isdigit(board[i][j]) && tmp[board[i][j] - '0']) {
              return false;
            } else if (isdigit(board[i][j])) {
              tmp[board[i][j] - '0'] = true;
            }
          }
        }
      }
    }

    return true;
  }
};
// Runtime: 16 ms, faster than 62.69%
// Memory Usage: 9.6 MB, less than 74.36%