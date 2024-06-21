class Solution {
 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                   vector<int>& click) {
    int m = board.size();
    int n = board[0].size();

    function<int(int, int)> count = [&](int y, int x) -> int {
      int cnt = 0;
      for (auto i : {-1, 0, 1}) {
        for (auto j : {-1, 0, 1}) {
          if (i == 0 && j == 0)
            continue;
          int dy = y + i;
          int dx = x + j;
          if (dy < 0 || dy == m || dx < 0 || dx == n)
            continue;
          if (board[dy][dx] == 'M' || board[dy][dx] == 'X')
            ++cnt;
        }
      }

      return cnt;
    };

    function<void(int, int)> dfs = [&](int y, int x) -> void {
      if (y < 0 || y == m || x < 0 || x == n)
        return;

      if (board[y][x] == 'B')
        return;

      if (board[y][x] == 'M') {
        board[y][x] = 'X';
      }

      if (board[y][x] == 'E') {
        int cnt = count(y, x);

        if (cnt > 0) {
          board[y][x] = cnt + '0';
        } else {
          board[y][x] = 'B';
          dfs(y, x + 1);
          dfs(y, x - 1);
          dfs(y + 1, x);
          dfs(y - 1, x);
          dfs(y + 1, x + 1);
          dfs(y + 1, x - 1);
          dfs(y - 1, x + 1);
          dfs(y - 1, x - 1);
        }
      }
    };

    dfs(click[0], click[1]);

    return board;
  }
};
// 10 ms
// 15.39 MB
