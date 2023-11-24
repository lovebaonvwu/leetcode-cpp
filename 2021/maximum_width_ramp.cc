class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    stack<int> stk;

    for (int i = 0; i < A.size(); ++i) {
      if (stk.empty() || A[i] < A[stk.top()]) {
        stk.push(i);
      }
    }

    int ans = 0;
    for (int i = A.size() - 1; i > ans; --i) {
      while (!stk.empty() && A[stk.top()] <= A[i]) {
        ans = max(ans, i - stk.top());
        stk.pop();
      }
    }

    return ans;
  }
};
// Runtime: 60 ms, faster than 86.94%
// Memory Usage: 13 MB, less than 75.00%

class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    vector<int> vec;

    int ans = 0;
    for (int i = 0; i < A.size(); ++i) {
      if (vec.empty() || A[i] < A[vec.back()]) {
        vec.push_back(i);
      } else {
        int lo = 0;
        int hi = vec.size() - 1;

        while (lo < hi) {
          int mid = lo + (hi - lo) / 2;

          if (A[vec[mid]] > A[i]) {
            lo = mid + 1;
          } else {
            hi = mid;
          }
        }

        ans = max(ans, i - vec[lo]);
      }
    }

    return ans;
  }
};
// Runtime: 68 ms, faster than 54.46%
// Memory Usage: 12.7 MB, less than 100.00%

class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    int ans = 0;
    for (int i = 0; i < A.size() - 1; ++i) {
      for (int j = A.size() - 1; j > i; --j) {
        if (A[j] >= A[i]) {
          ans = max(ans, j - i);
          break;
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    vector<vector<int>> mem(A.size(), vector<int>(A.size()));

    return mwr(A, 0, A.size() - 1, mem);
  }

  int mwr(vector<int>& a, int i, int j, vector<vector<int>>& mem) {
    if (i == j) {
      return 0;
    }

    if (mem[i][j] > 0) {
      return mem[i][j];
    }

    if (a[i] <= a[j]) {
      mem[i][j] = j - i;
    } else {
      mem[i][j] = max(mwr(a, i + 1, j, mem), mwr(a, i, j - 1, mem));
    }

    return mem[i][j];
  }
};
// Memory Limit Exceeded