class Solution {
  vector<pair<int, int>> dirs{{1, 0},  {-1, 0}, {0, -1}, {0, 1},
                              {1, -1}, {1, 1},  {-1, 1}, {-1, -1}};

 public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                          vector<int>& king) {
    vector<vector<int>> ans;

    vector<vector<int>> board(8, vector<int>(8));

    for (const auto& queen : queens) {
      board[queen[0]][queen[1]] = 1;
    }

    for (const auto& dir : dirs) {
      for (int i = king[0] + dir.first, j = king[1] + dir.second;
           i >= 0 && i < 8 && j >= 0 && j < 8;
           i += dir.first, j += dir.second) {
        if (board[i][j] == 1) {
          ans.push_back({i, j});
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 9.2 MB, less than 100.00%