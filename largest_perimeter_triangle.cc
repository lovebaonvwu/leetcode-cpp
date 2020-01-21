class Solution {
 public:
  int largestPerimeter(vector<int>& A) {
    sort(A.begin(), A.end(), greater<int>());

    int n = A.size();

    for (int i = 0, j, k; i < n - 2; ++i) {
      j = i + 1;
      k = i + 2;

      if (A[j] + A[k] > A[i]) {
        return A[i] + A[j] + A[k];
      }
    }

    return 0;
  }
};
// Runtime: 56 ms, faster than 50.10%
// Memory Usage: 10.6 MB, less than 50.00%