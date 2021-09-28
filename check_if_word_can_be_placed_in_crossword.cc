class Solution {
  int m, n;
  int dirs[5] = {0, 1, 0, -1, 0};

 public:
  bool placeWordInCrossword(vector<vector<char>>& board, string word) {
    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '#') {
          continue;
        }

        for (int k = 0; k < 4; ++k) {
          int x = i - dirs[k];
          int y = j - dirs[k + 1];

          if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#') {
            continue;
          }

          if (canPlace(board, word, i, j, k)) {
            return true;
          }
        }
      }
    }

    return false;
  }

  bool canPlace(vector<vector<char>>& board,
                string& word,
                int i,
                int j,
                int k) {
    for (auto c : word) {
      if (i < 0 || j < 0 || i >= m || j >= n) {
        return false;
      }

      if (!(board[i][j] == c || board[i][j] == ' ')) {
        return false;
      }

      i += dirs[k];
      j += dirs[k + 1];
    }

    if (i >= 0 && j >= 0 && i < m && j < n && board[i][j] != '#') {
      return false;
    }

    return true;
  }
};
// Runtime: 188 ms, faster than 95.83%
// Memory Usage: 59.2 MB, less than 58.33%
// 2021.9.28 at 奥盛大厦