class SubrectangleQueries {
  vector<vector<int>> rect;

 public:
  SubrectangleQueries(vector<vector<int>>& rectangle) { rect = rectangle; }

  void updateSubrectangle(int row1,
                          int col1,
                          int row2,
                          int col2,
                          int newValue) {
    for (int r = row1; r < row2 + 1; ++r) {
      for (int c = col1; c < col2 + 1; ++c) {
        rect[r][c] = newValue;
      }
    }
  }

  int getValue(int row, int col) { return rect[row][col]; }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
// Runtime: 104 ms, faster than 49.31%
// Memory Usage: 18.6 MB

class SubrectangleQueries {
  vector<vector<int>> rect, subs;

 public:
  SubrectangleQueries(vector<vector<int>>& rectangle) { swap(rect, rectangle); }

  void updateSubrectangle(int row1,
                          int col1,
                          int row2,
                          int col2,
                          int newValue) {
    subs.push_back({row1, row2, col1, col2, newValue});
  }

  int getValue(int row, int col) {
    for (int i = subs.size() - 1; i >= 0; --i) {
      if (row >= subs[i][0] && row <= subs[i][1] && col >= subs[i][2] &&
          col <= subs[i][3]) {
        return subs[i][4];
      }
    }

    return rect[row][col];
  }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
// Runtime: 76 ms, faster than 91.04%
// Memory Usage: 18.5 MB, less than 100.00%