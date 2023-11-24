class Solution {
 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m - 2; ++i) {
      for (int j = 0; j < n - 2; ++j) {
        vector<int> cnt(9);
        vector<int> sum;

        int d_sum_1 = 0;
        int d_sum_2 = 0;

        for (int p = 0; p < 3; ++p) {
          int r_sum = 0;
          int c_sum = 0;

          for (int q = 0; q < 3; ++q) {
            if (grid[i + p][j + q] > 9 || grid[i + p][j + q] == 0) {
              continue;
            }

            ++cnt[grid[i + p][j + q] - 1];
            r_sum += grid[i + q][j + p];
            c_sum += grid[i + p][j + q];

            if (p == q) {
              d_sum_1 += grid[i + p][j + q];
            }

            if (p == 2 - q) {
              d_sum_2 += grid[i + p][j + q];
            }
          }

          sum.push_back(r_sum);
          sum.push_back(c_sum);
        }

        sum.push_back(d_sum_1);
        sum.push_back(d_sum_2);

        if (all_of(cnt.begin(), cnt.end(), [](int n) { return n == 1; }) &&
            all_of(sum.begin(), sum.end(),
                   [&sum](int n) { return n == sum[0]; })) {
          ++ans;
        }
      }
    }

    return ans;
  }
};