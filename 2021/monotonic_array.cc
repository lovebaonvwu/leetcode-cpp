class Solution {
 public:
  bool isMonotonic(vector<int>& A) {
    if (A.size() < 2) {
      return true;
    }

    char inc = 0;

    for (int i = 1; i < A.size(); ++i) {
      if (!inc) {
        if (A[i - 1] - A[i] < 0) {
          inc = -1;
        } else if (A[i - 1] - A[i] > 0) {
          inc = 1;
        }
      } else if (inc > 0) {
        if (A[i - 1] - A[i] < 0) {
          return false;
        }
      } else if (inc < 0) {
        if (A[i - 1] - A[i] > 0) {
          return false;
        }
      }
    }

    return true;
  }
};  // 80ms

class Solution {
 public:
  bool isMonotonic(vector<int>& A) {
    if (A.size() < 2) {
      return true;
    }

    int i = 0;

    while (i + 1 < A.size() && A[i] == A[i + 1]) {
      ++i;
    }

    if (i >= A.size() - 2) {
      return true;
    }

    bool b = A[i] > A[i + 1];

    for (int j = i; j < A.size() - 1; ++j) {
      if (b) {
        if (A[j] < A[j + 1]) {
          return false;
        }
      } else {
        if (A[j] > A[j + 1]) {
          return false;
        }
      }
    }

    return true;
  }
};  // 80ms

class Solution {
 public:
  bool isMonotonic(vector<int>& A) {
    int inc = 0;
    int dec = 0;

    for (int i = 0; i < A.size() - 1; ++i) {
      if (A[i] < A[i + 1]) {
        ++inc;
      } else if (A[i] > A[i + 1]) {
        ++dec;
      }
    }

    return (inc && !dec) || (!inc && dec) || (!inc && !dec);
  }
};  // 88ms