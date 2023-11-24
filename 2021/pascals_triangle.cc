class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 0) {
      return vector<vector<int>>{};
    }

    if (numRows == 1) {
      return vector<vector<int>>{{1}};
    }

    if (numRows == 2) {
      return vector<vector<int>>{{1}, {1, 1}};
    }

    vector<vector<int>> ans{{1}, {1, 1}};

    for (int i = 2; i < numRows; ++i) {
      vector<int> line(i + 1);
      line[0] = line[i] = 1;

      for (int j = 1; j < i; ++j) {
        line[j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }

      ans.push_back(line);
    }

    return ans;
  }
};