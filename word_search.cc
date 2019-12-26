class Solution {
  int m, n;

 public:
  bool exist(vector<vector<char>>& board, string word) {
    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == word[0]) {
          if (dfs(board, i, j, word, 0)) {
            return true;
          }
        }
      }
    }

    return false;
  }

  bool dfs(vector<vector<char>>& board, int i, int j, string& word, int lvl) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[lvl]) {
      return false;
    }

    if (lvl == word.size() - 1) {
      return true;
    }

    char tmp = board[i][j];

    board[i][j] = '*';

    bool res = dfs(board, i - 1, j, word, lvl + 1) ||
               dfs(board, i, j + 1, word, lvl + 1) ||
               dfs(board, i + 1, j, word, lvl + 1) ||
               dfs(board, i, j - 1, word, lvl + 1);

    board[i][j] = tmp;

    return res;
  }
};
// Runtime: 20 ms, faster than 96.82%
// Memory Usage: 10 MB, less than 100.00%

class Solution {
  vector<pair<int, int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int m, n;

 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (word.empty()) {
      return true;
    }

    if (board.size() == 0) {
      return false;
    }

    m = board.size();
    n = board[0].size();

    vector<vector<int>> visited(m, vector<int>(n, false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == word[0]) {
          if (dfs(board, i, j, word, 0, visited)) {
            return true;
          }
        }
      }
    }

    return false;
  }

  bool dfs(vector<vector<char>>& board,
           int i,
           int j,
           string& word,
           int lvl,
           vector<vector<int>> visited) {
    if (lvl == word.size() - 1) {
      return true;
    }

    for (const auto& dir : dirs) {
      pair<int, int> neighbor = {i + dir.first, j + dir.second};
      if (neighbor.first >= 0 && neighbor.first < m && neighbor.second >= 0 &&
          neighbor.second < n && !visited[neighbor.first][neighbor.second] &&
          board[neighbor.first][neighbor.second] == word[lvl + 1]) {
        visited[i][j] = true;

        if (dfs(board, neighbor.first, neighbor.second, word, lvl + 1,
                visited)) {
          return true;
        }
      }
    }

    return false;
  }
};
// Runtime: 280 ms, faster than 27.71%
// Memory Usage: 195.9 MB, less than 14.71%