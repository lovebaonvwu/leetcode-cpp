class Solution {
 public:
  int smallestRangeI(vector<int>& A, int K) {
    return max(0, *max_element(A.begin(), A.end()) - 2 * K -
                      *min_element(A.begin(), A.end()));
  }
};
// Runtime: 20 ms, faster than 88.62%
// Memory Usage: 9.1 MB, less than 100.00%

class Solution {
 public:
  int smallestRangeI(vector<int>& A, int K) {
    int mx = *max_element(A.begin(), A.end());
    int mi = *min_element(A.begin(), A.end());

    return mx - 2 * K > mi ? mx - 2 * K - mi : 0;
  }
};
// Runtime: 20 ms, faster than 88.62%
// Memory Usage: 8.9 MB, less than 100.00%