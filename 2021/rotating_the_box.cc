class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int row = box.size(), col = box[0].size();

    for (auto& b : box) {
      for (int i = col - 1, j = i; j >= 0; --j) {
        if (b[j] == '*') {
          i = j - 1;
        } else if (b[j] == '#') {
          if (b[i] == '.') {
            b[i--] = '#';
            b[j] = '.';
          } else {
            i = j - 1;
          }
        }
      }
    }

    vector<vector<char>> ans(col, vector<char>(row));

    for (int i = 0; i < col; ++i) {
      for (int j = 0; j < row; ++j) {
        ans[i][j] = box[row - 1 - j][i];
      }
    }

    return ans;
  }
};
// Runtime: 280 ms, faster than 64.36%
// Memory Usage: 52.6 MB, less than 57.07%

class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int row = box.size(), col = box[0].size();

    vector<vector<char>> ans(col, vector<char>(row, '.'));

    for (int i = 0; i < row; ++i) {
      for (int j = col - 1, k = j; j >= 0; --j) {
        if (box[i][j] != '.') {
          k = box[i][j] == '*' ? j : k;
          ans[k--][row - 1 - i] = box[i][j];
        }
      }
    }

    return ans;
  }
};
// Runtime: 276 ms, faster than 64.96%
// Memory Usage: 52.6 MB, less than 35.99%