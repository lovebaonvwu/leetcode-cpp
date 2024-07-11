class Solution {
 public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    int m = picture.size();
    int n = picture[0].size();

    vector<int> row(m);
    vector<int> col(n);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (picture[i][j] == 'B') {
          ++row[i];
          ++col[j];
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (picture[i][j] == 'B') {
          if (row[i] == 1 && col[j] == 1)
            ++ans;
        }
      }
    }

    return ans;
  }
};
// 55 ms
// 20.54 MB