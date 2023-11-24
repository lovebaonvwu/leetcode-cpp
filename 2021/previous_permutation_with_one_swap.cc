class Solution {
 public:
  vector<int> prevPermOpt1(vector<int>& A) {
    int m = -1;
    int n = -1;

    for (int i = A.size() - 1; i > 0; --i) {
      if (A[i - 1] > A[i]) {
        m = i - 1;
        break;
      }
    }

    if (m < 0) {
      return A;
    }

    for (int i = A.size() - 1; i >= 0; --i) {
      if (A[i] < A[m]) {
        n = i;
        break;
      }
    }

    while (n > 0 && A[n - 1] == A[n]) {
      --n;
    }

    swap(A[m], A[n]);

    return A;
  }
};
// Runtime: 64 ms, faster than 10.60%
// Memory Usage: 24.5 MB, less than 99.54%