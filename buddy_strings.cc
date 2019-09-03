class Solution {
 public:
  bool buddyStrings(string A, string B) {
    if ((A.size() != B.size()) || (A.empty() && B.empty())) {
      return false;
    }

    int m = -1;
    int n = -1;

    bool same = true;
    char alpha = 0;

    for (int i = 0; i < A.size(); ++i) {
      if (!alpha) {
        alpha = A[i];
      } else if (A[i] != alpha) {
        same = false;
      }

      if (A[i] != B[i] && m < 0) {
        m = i;
      } else if (A[i] != B[i] && n < 0) {
        n = i;
      } else if (A[i] != B[i]) {
        return false;
      }
    }

    int subA = unordered_set<char>(A.begin(), A.end()).size();

    return (m < 0 && n < 0 && !same && subA < B.size()) ||
           (m < 0 && n < 0 && same) ||
           m >= 0 && n >= 0 && A[m] == B[n] && A[n] == B[m];
  }
};  // 4ms

class Solution {
 public:
  bool buddyStrings(string A, string B) {
    if (A.size() != B.size()) {
      return false;
    }

    int aSize = unordered_set<char>(A.begin(), A.end()).size();

    if (A == B && aSize < B.size()) {
      return true;
    }

    int m = -1;
    int n = -1;

    for (int i = 0; i < A.size(); ++i) {
      if (A[i] != B[i] && m < 0) {
        m = i;
      } else if (A[i] != B[i] && n < 0) {
        n = i;
      } else if (A[i] != B[i]) {
        return false;
      }
    }

    return m >= 0 && n >= 0 && A[m] == B[n] && B[m] == A[n];
  }
};  // 8ms