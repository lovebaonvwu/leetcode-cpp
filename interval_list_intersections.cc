class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                           vector<vector<int>>& B) {
    vector<vector<int>> ans;

    for (int i = 0, j = 0; i < A.size() && j < B.size();) {
      if (A[i][1] < B[j][0]) {
        ++i;
        continue;
      }

      if (B[j][1] < A[i][0]) {
        ++j;
        continue;
      }

      ans.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});

      A[i][1] < B[j][1] ? ++i : ++j;
    }

    return ans;
  }
};
// Runtime: 52 ms, faster than 77.46%
// Memory Usage: 15.7 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                           vector<vector<int>>& B) {
    vector<vector<int>> ans;

    for (int i = 0, j = 0; i < A.size() && j < B.size();) {
      if (A[i][1] < B[j][0]) {
        ++i;
        continue;
      }

      if (B[j][1] < A[i][0]) {
        ++j;
        continue;
      }

      vector<int> p;
      if (A[i][0] <= B[j][0]) {
        p.push_back(B[j][0]);

        if (A[i][1] <= B[j][1]) {
          p.push_back(A[i][1]);
          ++i;
        } else {
          p.push_back(B[j][1]);
          ++j;
        }
      } else {
        p.push_back(A[i][0]);

        if (B[j][1] <= A[i][1]) {
          p.push_back(B[j][1]);
          ++j;
        } else {
          p.push_back(A[i][1]);
          ++i;
        }
      }

      ans.push_back(p);
    }

    return ans;
  }
};
// Runtime: 56 ms, faster than 48.46%
// Memory Usage: 16.9 MB, less than 12.00%