class Solution {
 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> jump;
    jump.push_back(-1);

    bool left2right = true;
    for (int i = n - 1; i >= 0; --i) {
      int step = 1;
      int j = 0;
      if (!left2right) {
        j = n - 1;
        step = -1;
      }

      while (j >= 0 && j < n) {
        jump.push_back(board[i][j]);
        j += step;
      }

      left2right = !left2right;
    }

    queue<int> q;
    q.push(1);
    vector<int> dp(n * n + 1, -1);
    dp[1] = 0;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next = cur + 1; next <= min(cur + 6, n * n); ++next) {
        int destination = jump[next] == -1 ? next : jump[next];
        if (dp[destination] == -1) {
          dp[destination] = dp[cur] + 1;
          q.push(destination);
        }
      }
    }

    return dp[n * n];
  }
};
// Runtime 22 ms
// Memory 13.7 MB
// 2023.1.24 at 茗筑美嘉