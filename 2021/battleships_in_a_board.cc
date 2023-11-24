class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    int ans = 0;

    size_t m = board.size();
    size_t n = board[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X') {
          ++ans;
          if (i + 1 < m && board[i + 1][j] == 'X') {
            for (int k = i; k < m && board[k][j] == 'X'; ++k) {
              board[k][j] = '.';
            }
          } else if (j + 1 < n && board[i][j + 1] == 'X') {
            for (int k = j; k < n && board[i][k] == 'X'; ++k) {
              board[i][k] = '.';
            }
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 39.08%
// Memory Usage: 8.3 MB, less than 40.98%

class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    int ans = 0;

    size_t m = board.size();
    size_t n = board[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') &&
            (j == 0 || board[i][j - 1] == '.')) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 57.42%
// Memory Usage: 8.3 MB, less than 28.68%