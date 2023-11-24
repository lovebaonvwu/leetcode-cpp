class Solution {
 public:
  int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        matrix[i][j] ^= matrix[i][j - 1];
      }
    }

    for (int j = 0; j < n; ++j) {
      for (int i = 1; i < m; ++i) {
        matrix[i][j] ^= matrix[i - 1][j];
      }
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        pq.push(matrix[i][j]);

        if (pq.size() > k) {
          pq.pop();
        }
      }
    }

    return pq.top();
  }
};
// Runtime: 1000 ms, faster than 12.34%
// Memory Usage: 99.1 MB, less than 90.26%

class Solution {
 public:
  int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int left = j > 0 ? matrix[i][j - 1] : 0;
        int top = i > 0 ? matrix[i - 1][j] : 0;
        int top_left = (i > 0 && j > 0) ? matrix[i - 1][j - 1] : 0;

        matrix[i][j] ^= left ^ top ^ top_left;

        pq.push(matrix[i][j]);

        if (pq.size() > k) {
          pq.pop();
        }
      }
    }

    return pq.top();
  }
};
// Runtime: 584 ms, faster than 57.05%
// Memory Usage: 99.2 MB, less than 90.26%