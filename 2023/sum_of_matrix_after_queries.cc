class Solution {
 public:
  long long matrixSumQueries(int n, vector<vector<int>>& queries) {
    vector<bool> row(n), col(n);
    int row_cnt = n, col_cnt = n;

    long long ans = 0;
    for (int i = queries.size() - 1; i >= 0; --i) {
      int type = queries[i][0], index = queries[i][1], val = queries[i][2];

      if (type == 0) {
        if (!row[index]) {
          row[index] = true;
          --row_cnt;
          ans += val * col_cnt;
        }
      } else {
        if (!col[index]) {
          col[index] = true;
          --col_cnt;
          ans += val * row_cnt;
        }
      }
    }

    return ans;
  }
};
// Runtime 641 ms
// Memory 190.7 MB