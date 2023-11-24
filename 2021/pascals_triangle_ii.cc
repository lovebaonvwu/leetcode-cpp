class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1, 0);

    ans[0] = 1;

    for (int i = 1; i <= rowIndex; ++i) {
      for (int j = i; j > 0; --j) {
        ans[j] += ans[j - 1];
      }
    }

    return ans;
  }
};  // 0ms 8.4MB

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> rows;
    rows.push_back({1});
    rows.push_back({1, 1});

    for (int i = 2; i <= rowIndex; ++i) {
      vector<int> row(i + 1);
      row[0] = 1;
      row[row.size() - 1] = 1;

      for (int j = 1; j < row.size() - 1; ++j) {
        row[j] = rows[i - 1][j - 1] + rows[i - 1][j];
      }

      rows.push_back(row);
    }

    return rows[rowIndex];
  }
};  // 4ms 8.7MB