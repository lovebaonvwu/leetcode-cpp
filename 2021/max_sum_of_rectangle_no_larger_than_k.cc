class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();

    int ans = INT_MIN;
    for (int l = 0; l < n; ++l) {
      vector<int> row(m, 0);

      for (int r = l; r < n; ++r) {
        for (int i = 0; i < m; ++i) {
          row[i] += matrix[i][r];
        }

        int curSum = 0;
        set<int> st;
        st.insert(0);

        for (auto val : row) {
          curSum += val;
          auto it = st.lower_bound(curSum - k);
          if (it != st.end()) {
            ans = max(ans, curSum - *it);
          }

          st.insert(curSum);
        }
      }
    }

    return ans;
  }
};
// Runtime: 1060 ms, faster than 38.09%
// Memory Usage: 294 MB, less than 15.28%
// 2021.7.3