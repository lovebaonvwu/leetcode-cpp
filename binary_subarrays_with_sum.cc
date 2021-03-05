class Solution {
 public:
  int numSubarraysWithSum(vector<int>& A, int S) {
    int ans = 0;

    for (int i = 0, j = 0; j < A.size(); ++j) {
      S -= A[j];

      if (S > 0) {
        continue;
      }

      while (S < 0 && i < j) {
        S += A[i++];
      }

      if (S == 0) {
        ++ans;
      }

      int p = i;
      while (p < j && A[p] == 0) {
        ++p;
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 89.78%
// Memory Usage: 25.7 MB, less than 95.06%