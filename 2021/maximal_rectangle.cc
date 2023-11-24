class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) {
      return 0;
    }

    int n = matrix[0].size();

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      vector<int> row(n);

      for (int j = i; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
          if (matrix[j][k] == '0') {
            row[k] = 0;
          } else {
            ++row[k];
          }
        }

        ans = max(ans, maxHistogramArea(row));
      }
    }

    return ans;
  }

  int maxHistogramArea(vector<int>& row) {
    stack<int> stk;

    int maxArea = 0;

    for (int i = 0; i < row.size();) {
      if (stk.empty() || row[i] >= row[stk.top()]) {
        stk.push(i++);
      } else {
        int top = stk.top();
        stk.pop();

        int area = 0;
        if (stk.empty()) {
          area = row[top] * i;
        } else {
          area = row[top] * (i - stk.top() - 1);
        }

        maxArea = max(maxArea, area);
      }
    }

    while (!stk.empty()) {
      int top = stk.top();
      stk.pop();

      int area = 0;
      if (stk.empty()) {
        area = row[top] * row.size();
      } else {
        area = row[top] * (row.size() - stk.top() - 1);
      }

      maxArea = max(maxArea, area);
    }

    return maxArea;
  }
};
// Runtime: 792 ms, faster than 5.05%
// Memory Usage: 59.6 MB, less than 5.09%
// 2021.11.30 at 奥盛大厦