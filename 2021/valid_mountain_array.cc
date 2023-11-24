class Solution {
 public:
  bool validMountainArray(vector<int>& A) {
    if (A.empty()) {
      return false;
    }

    int cnt = 0;

    for (int i = 0; i < A.size() - 1; ++i) {
      if (A[i] >= A[i + 1]) {
        break;
      }

      ++cnt;
    }

    if (cnt == 0 || cnt == A.size() - 1) {
      return false;
    }

    for (int i = cnt; i < A.size() - 1; ++i) {
      if (A[i] <= A[i + 1]) {
        break;
      }

      ++cnt;
    }

    return cnt == A.size() - 1;
  }
};  // 36ms

class Solution {
 public:
  bool validMountainArray(vector<int>& A) {
    if (A.empty()) {
      return false;
    }

    int up = 0;
    int down = 0;

    for (int i = 0; i < A.size() - 1; ++i) {
      if (A[i] == A[i + 1]) {
        return false;
      }

      if (A[i] < A[i + 1] && down) {
        return false;
      }

      if (A[i] < A[i + 1]) {
        up = 1;
      } else {
        down = 1;
      }
    }

    return up && down;
  }
};  // 40ms