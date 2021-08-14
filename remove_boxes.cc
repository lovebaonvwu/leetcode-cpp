class Solution {
  vector<int> b;
  int dp[100][100][100];

 public:
  int removeBoxes(vector<int>& boxes) {
    b = boxes;

    return dfs(0, boxes.size() - 1, 0);
  }

  int dfs(int l, int r, int k) {
    if (l > r) {
      return 0;
    }

    if (dp[l][r][k]) {
      return dp[l][r][k];
    }

    int cnt = k;
    int i = r;

    while (i >= l && b[i] == b[r]) {
      --i;
      ++cnt;
    }

    dp[l][r][k] = dfs(l, i, 0) + cnt * cnt;

    for (int j = i; j >= l; --j) {
      if (b[j] != b[r]) {
        continue;
      }

      if (b[j] == b[r] && b[j + 1] == b[r]) {
        continue;
      }

      dp[l][r][k] = max(dp[l][r][k], dfs(l, j, cnt) + dfs(j + 1, i, 0));
    }

    return dp[l][r][k];
  }
};
// Runtime: 130 ms, faster than 65.91%
// Memory Usage: 12.1 MB, less than 70.43%
// 2021.8.14 at 茗筑美嘉