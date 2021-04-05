class Solution {
 public:
  bool isIdealPermutation(vector<int>& A) {
    int local = 0, global = 0;

    for (int i = 0; i < A.size() - 1; ++i) {
      if (A[i] > A[i + 1]) {
        ++local;
      }

      for (int j = i + 1; j < A.size(); ++j) {
        if (A[i] > A[j]) {
          ++global;
        }
      }
    }

    return global == local;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  bool isIdealPermutation(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
      if (abs(A[i] - i) > 1) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 48 ms, faster than 61.16%
// Memory Usage: 35.6 MB, less than 53.35%