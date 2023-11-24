class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); ++i) {
      int l = 0;
      int r = A[i].size() - 1;

      while (l <= r) {
        if (A[i][l] == A[i][r]) {
          if (A[i][l] == 0) {
            A[i][l] = 1;
            A[i][r] = 1;
          } else {
            A[i][l] = 0;
            A[i][r] = 0;
          }
        }

        ++l;
        --r;
      }
    }

    return A;
  }
};