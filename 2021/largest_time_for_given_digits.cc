class Solution {
 public:
  string largestTimeFromDigits(vector<int>& A) {
    sort(A.begin(), A.end(), greater<int>());

    do {
      if ((A[0] < 2 || A[0] == 2 && A[1] < 4) && A[2] < 6) {
        return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) +
               to_string(A[3]);
      }
    } while (prev_permutation(A.begin(), A.end()));

    return "";
  }
};
// Runtime: 4 ms, faster than 63.92%
// Memory Usage: 8.1 MB, less than 100.00%