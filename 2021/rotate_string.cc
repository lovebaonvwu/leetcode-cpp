class Solution {
 public:
  bool rotateString(string A, string B) {
    return A.size() == B.size() && (A + A).find(B) != string::npos;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.3 MB, less than 73.33%

class Solution {
 public:
  bool rotateString(string A, string B) {
    if (A.size() != B.size()) {
      return false;
    }

    if (A == B) {
      return true;
    }

    size_t n = A.size();

    for (int i = 0; i < n; ++i) {
      bool find = true;

      for (int k = 0, j = i; k < n; ++k, ++j) {
        j %= n;
        if (A[j] != B[k]) {
          find = false;
          break;
        }
      }

      if (find) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 63.24%
// Memory Usage: 8.3 MB, less than 86.67%