class Solution {
 public:
  double knightProbability(int n, int k, int row, int column) {
    vector<vector<double>> dp(n, vector<double>(n));
    dp[row][column] = 1;
    int dirs[8][2] = {{1, 2},   {2, 1},   {2, -1}, {1, -2},
                      {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

    int K = k;
    for (int k = 0; k < K; ++k) {
      vector<vector<double>> tmp(n, vector<double>(n));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          for (int m = 0; m < 8; ++m) {
            int di = i + dirs[m][0];
            int dj = j + dirs[m][1];

            if (di < 0 || di >= n || dj < 0 || dj >= n) {
              continue;
            }

            tmp[i][j] += dp[di][dj];
          }
        }
      }
      std::swap(dp, tmp);
    }

    double cnt = 0.0f;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cnt += dp[i][j];
      }
    }

    return cnt / pow(8, K);
  }
};
// 25 ms
// 9.40mb