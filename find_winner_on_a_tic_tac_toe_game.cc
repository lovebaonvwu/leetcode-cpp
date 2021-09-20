class Solution {
 public:
  string tictactoe(vector<vector<int>>& moves) {
    vector<int> A(8), B(8);

    for (int i = 0; i < moves.size(); ++i) {
      int r = moves[i][0];
      int c = moves[i][1];

      vector<int>& p = (i & 1) ? B : A;
      ++p[r];
      ++p[3 + c];

      if (r == c) {
        ++p[6];
      }
      if (r + c == 2) {
        ++p[7];
      }
    }

    for (int i = 0; i < 8; ++i) {
      if (A[i] == 3) {
        return "A";
      }

      if (B[i] == 3) {
        return "B";
      }
    }

    return moves.size() == 9 ? "Draw" : "Pending";
  }
};
// Runtime: 4 ms, faster than 48.91%
// Memory Usage: 8.4 MB, less than 56.45%
// 2021.9.20 at 茗筑美嘉