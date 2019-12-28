class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();

    int lo = matrix[0][0];
    int hi = matrix[n - 1][n - 1];

    while (lo < hi) {
      int cnt = 0;

      int mid = lo + (hi - lo) / 2;

      int j = n - 1;
      for (int i = 0; i < n; ++i) {
        while (j >= 0 && matrix[i][j] > mid) {
          --j;
        }

        cnt += j + 1;
      }

      if (cnt < k) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    return lo;
  }
};
// Runtime: 36 ms, faster than 95.42%
// Memory Usage: 12 MB, less than 100.00%

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq;

    int n = matrix.size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pq.size() < k) {
          pq.push(matrix[i][j]);
        } else if (matrix[i][j] < pq.top()) {
          pq.pop();
          pq.push(matrix[i][j]);
        }
      }
    }

    return pq.top();
  }
};
// Runtime: 52 ms, faster than 58.77%
// Memory Usage: 13.2 MB, less than 36.36%