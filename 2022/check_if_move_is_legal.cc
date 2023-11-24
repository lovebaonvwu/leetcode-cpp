class Solution {
 public:
  bool checkMove(vector<vector<char>>& board,
                 int rMove,
                 int cMove,
                 char color) {
    int dirs[] = {0, 1, 0, -1, 0, 1, 1, -1, -1, 1};

    for (int k = 0; k < 9; ++k) {
      for (int i = 1;; ++i) {
        int dx = rMove + i * dirs[k];
        int dy = cMove + i * dirs[k + 1];

        if (dx < 0 || dy < 0 || dx >= 8 || dy >= 8 || board[dx][dy] == '.') {
          break;
        }

        if (board[dx][dy] == color) {
          if (i > 1) {
            return true;
          }

          break;
        }
      }
    }

    return false;
  }
};
// Runtime: 18 ms, faster than 24.14%
// Memory Usage: 11.1 MB, less than 58.62%
// 2022.10.12 at 奥盛大厦