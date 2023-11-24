class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        mp[mat[i][j]] = make_pair(i, j);
      }
    }

    vector<int> rows(m), cols(n);
    for (int k = 0; k < arr.size(); ++k) {
      auto& [i, j] = mp[arr[k]];
      ++rows[i], ++cols[j];

      if (rows[i] == n || cols[j] == m) {
        return k;
      }
    }

    return -1;
  }
};
// Runtime 409 ms
// Memory 164.2 MB
