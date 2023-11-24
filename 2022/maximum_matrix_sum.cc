class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long sum = 0;
    int zero_cnt = 0, neg_cnt = 0, min_num = INT_MAX;
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sum += abs(matrix[i][j]);
        zero_cnt += matrix[i][j] == 0;
        min_num = min(min_num, abs(matrix[i][j]));
        neg_cnt += matrix[i][j] < 0;
      }
    }

    return sum - (zero_cnt || neg_cnt % 2 == 0 ? 0 : 2 * min_num);
  }
};
// Runtime: 174 ms, faster than 74.74%
// Memory Usage: 35.2 MB, less than 68.94%
// 2022.5.13 at 奥盛大厦