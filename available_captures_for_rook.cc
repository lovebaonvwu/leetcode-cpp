class Solution {
 public:
  int numRookCaptures(vector<vector<char>>& board) {
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    pair<int, int> rook;
    for (int i = 0; i < 8; ++i) {
      bool findRook = false;
      for (int j = 0; j < 8; ++j) {
        if (board[i][j] == 'R') {
          findRook = true;
          rook = {i, j};
          break;
        }
      }

      if (findRook) {
        break;
      }
    }

    int ans = 0;
    for (auto& [i, j] : moves) {
      for (int x = rook.first + i, y = rook.second + j;
           x >= 0 && x < 8 && y >= 0 && y < 8; x += i, y += j) {
        if (board[x][y] == 'B') {
          break;
        } else if (board[x][y] == 'p') {
          ++ans;
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7 MB, less than 100.00%

class Solution {
 public:
  int numRookCaptures(vector<vector<char>>& board) {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (board[i][j] == 'R') {
          return cap(board, i, j, 0, 1) + cap(board, i, j, 0, -1) +
                 cap(board, i, j, 1, 0) + cap(board, i, j, -1, 0);
        }
      }
    }

    return 0;
  }

  int cap(vector<vector<char>>& b, int i, int j, int x, int y) {
    for (; i >= 0 && i < 8 && j >= 0 && j < 8 && b[i][j] != 'B';
         i += x, j += y) {
      if (b[i][j] == 'p') {
        return 1;
      }
    }

    return 0;
  }
};
// Runtime: 4 ms, faster than 5.12%
// Memory Usage: 6.9 MB, less than 100.00%