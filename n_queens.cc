class Solution {
  vector<bool> cols;
  vector<bool> diag1;
  vector<bool> diag2;
  vector<string> board;
  vector<vector<string>> ans;

  int N;

 public:
  vector<vector<string>> solveNQueens(int n) {
    N = n;
    cols = vector<bool>(n, false);
    diag1 = vector<bool>(2 * n - 1, false);
    diag2 = vector<bool>(2 * n - 1, false);
    board = vector<string>(n, string(n, '.'));

    dfs(0);

    return ans;
  }

 private:
  bool canPlace(int r, int c) {
    return !cols[c] && !diag1[r + c] && !diag2[c - r + (N - 1)];
  }

  void placeQueen(int r, int c, bool place) {
    cols[c] = place;
    diag1[r + c] = place;
    diag2[c - r + (N - 1)] = place;
    board[r][c] = place ? 'Q' : '.';
  }

  void dfs(int r) {
    if (r == N) {
      ans.push_back(board);
      return;
    }

    for (int i = 0; i < N; ++i) {
      if (canPlace(r, i)) {
        placeQueen(r, i, true);
        dfs(r + 1);
        placeQueen(r, i, false);
      }
    }
  }
};
// Runtime: 4 ms, faster than 95.55%
// Memory Usage: 7.4 MB, less than 68.41%