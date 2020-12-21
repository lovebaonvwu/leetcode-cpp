class Solution {
 public:
  int smallestRangeII(vector<int>& A, int K) {
    sort(A.begin(), A.end());

    int n = A.size();

    int ans = A[n - 1] - A[0];

    for (int i = 0; i < n - 1; ++i) {
      int mx = max(A[i] + K, A[n - 1] - K);
      int mn = min(A[i + 1] - K, A[0] + K);

      ans = min(ans, mx - mn);
    }

    return ans;
  }
};
// Runtime: 48 ms, faster than 92.93%
// Memory Usage: 15.8 MB, less than 88.59%