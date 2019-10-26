class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    int i = 0;
    int j = A.size() - 1;
    while (i < j) {
      while (i < j && A[i] % 2 == 0) {
        ++i;
      }

      while (i < j && A[j] % 2 != 0) {
        --j;
      }

      swap(A[i], A[j]);
    }

    return A;
  }
};
// Runtime: 24 ms, faster than 97.02%
// Memory Usage: 9.5 MB, less than 100.00%

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    for (int i = 0, j = 0; j < A.size(); ++j) {
      if (A[j] % 2 == 0) {
        swap(A[i++], A[j]);
      }
    }

    return A;
  }
};
// Runtime: 28 ms, faster than 76.54%
// Memory Usage: 9.7 MB, less than 63.79%

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    vector<int> odd;
    vector<int> even;

    for (const auto& n : A) {
      if (n % 2 == 0) {
        even.push_back(n);
      } else {
        odd.push_back(n);
      }
    }

    even.insert(even.end(), odd.begin(), odd.end());
    return even;
  }
};
// Runtime: 28 ms, faster than 76.54%
// Memory Usage: 10.1 MB, less than 18.97%

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    int n = A.size();
    int i = 0;
    int j = A.size() - 1;
    while (i < j) {
      while (i < n && A[i] % 2 == 0) {
        ++i;
      }

      while (j >= 0 && A[j] % 2 != 0) {
        --j;
      }

      if (i < j) {
        swap(A[i], A[j]);
      }
    }

    return A;
  }
};
// Runtime: 32 ms, faster than 27.34%
// Memory Usage: 9.7 MB, less than 63.79%

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] % 2 == 0) {
        continue;
      }

      for (int j = i + 1; j < A.size(); ++j) {
        if (A[j] % 2 == 0) {
          swap(A[i], A[j]);
          break;
        }
      }
    }

    return A;
  }
};
// Runtime: 76 ms, faster than 7.49%
// Memory Usage: 9.5 MB, less than 100.00%