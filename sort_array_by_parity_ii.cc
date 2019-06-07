class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    int size = A.size();

    int i = 0;
    int j = 1;

    while (i < size && j < size) {
      while (i < size && (A[i] & 1) == 0) {
        i += 2;
      }

      while (j < size && (A[j] & 1) == 1) {
        j += 2;
      }

      if (i < size && j < size) {
        swap(A[i], A[j]);
        i += 2;
        j += 2;
      }
    }

    return A;
  }
};  // 84ms

class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    int size = A.size();

    if (size < 2) {
      return A;
    }

    int i = 0;
    int j = 1;

    while (i < size && j < size) {
      while (i < size && i % 2 == 0 && A[i] % 2 == 0) {
        i += 2;
      }

      while (j < size && j % 2 != 0 && A[j] % 2 != 0) {
        j += 2;
      }

      if (i < size && j < size) {
        swap(A[i], A[j]);
        i += 2;
        j += 2;
      }
    }

    return A;
  }
};  // 84ms

class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    if (A.size() < 2) {
      return A;
    }

    int i = 0;
    int j = 1;

    while (i < A.size() && j < A.size()) {
      while (i < A.size() && i % 2 == 0 && A[i] % 2 == 0) {
        i += 2;
      }

      while (j < A.size() && j % 2 != 0 && A[j] % 2 != 0) {
        j += 2;
      }

      if (i < A.size() && j < A.size()) {
        swap(A[i], A[j]);
        i += 2;
        j += 2;
      }
    }

    return A;
  }
};  // 100ms