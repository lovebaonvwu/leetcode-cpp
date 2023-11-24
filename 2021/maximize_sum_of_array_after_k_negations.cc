class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& A, int K) {
    sort(A.begin(), A.end());

    for (int i = 0; i < A.size() && K > 0 && A[i] < 0; ++i, --K) {
      A[i] = -A[i];
    }

    return accumulate(A.begin(), A.end(), 0) -
           (K % 2) * *min_element(A.begin(), A.end()) * 2;
  }
};
// Runtime: 8 ms, faster than 68.15%
// Memory Usage: 8.6 MB, less than 100.00%

class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& A, int K) {
    int min = 0;

    sort(A.begin(), A.end());

    for (int i = 0; i < A.size() && K > 0; ++i) {
      if (A[i] < 0) {
        A[i] = -A[i];
        --K;
      } else if (A[i] == 0) {
        K = 0;
      }

      if (A[i] < A[min]) {
        min = i;
      }
    }

    if (K > 0 && K % 2 != 0) {
      A[min] = -A[min];
    }

    return accumulate(A.begin(), A.end(), 0);
  }
};
// Runtime: 8 ms, faster than 68.15%
// Memory Usage: 8.6 MB, less than 100.00%

class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& A, int K) {
    sort(A.begin(), A.end());

    for (int i = 0; i < A.size() && K > 0; ++i) {
      if (A[i] < 0) {
        A[i] = -A[i];
        --K;
      } else if (A[i] == 0) {
        K = 0;
      } else {
        break;
      }
    }

    if (K > 0 && K % 2 != 0) {
      sort(A.begin(), A.end());
      A[0] = -A[0];
    }

    return accumulate(A.begin(), A.end(), 0);
  }
};
// Runtime: 12 ms, faster than 23.97%
// Memory Usage: 8.5 MB, less than 100.00%