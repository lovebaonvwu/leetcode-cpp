class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    int ans = 0;

    int str_len = A[0].size();

    for (int i = 0; i < str_len; ++i) {
      char prev = A[0][i];

      bool sorted = true;
      for (int j = 1; j < A.size(); ++j) {
        if (A[j][i] < prev) {
          sorted = false;
          break;
        } else {
          prev = A[j][i];
        }
      }

      if (!sorted) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 64 ms, faster than 28.03%
// Memory Usage: 11 MB, less than 100.00%

class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    int ans = 0;

    for (int i = 0; i < A[0].size(); ++i) {
      for (int j = 1; j < A.size(); ++j) {
        if (A[j][i] < A[j - 1][i]) {
          ++ans;
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 64 ms, faster than 28.03%
// Memory Usage: 10.8 MB, less than 100.00%

class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    int str_len = A[0].size();

    vector<int> visited(str_len);

    int ans = 0;
    for (int i = 1; i < A.size(); ++i) {
      for (int j = 0; j < str_len; ++j) {
        if (visited[j]) {
          continue;
        }

        if (A[i][j] < A[i - 1][j]) {
          ++ans;
          visited[j] = 1;
        }
      }
    }

    return ans;
  }
};
// Runtime: 68 ms, faster than 14.19%
// Memory Usage: 11 MB, less than 100.00%