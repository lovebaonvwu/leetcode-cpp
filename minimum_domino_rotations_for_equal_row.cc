class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    const int n = 7;
    vector<int> cnt_a(n);
    vector<int> cnt_b(n);
    vector<int> same(n);

    for (int i = 0; i < A.size(); ++i) {
      ++cnt_a[A[i]];
      ++cnt_b[B[i]];

      if (A[i] == B[i]) {
        ++same[A[i]];
      }
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; ++i) {
      if (cnt_a[i] + cnt_b[i] - same[i] == A.size()) {
        int tmp = min(cnt_a[i], cnt_b[i]) - same[i];
        ans = min(ans, tmp);
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
// Runtime: 120 ms, faster than 82.76%
// Memory Usage: 19.2 MB, less than 83.33%

class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    const int n = 7;
    vector<int> cnt_a(n);
    vector<int> cnt_b(n);
    vector<int> same(n);

    for (int i = 0; i < A.size(); ++i) {
      ++cnt_a[A[i]];
      ++cnt_b[B[i]];

      if (A[i] == B[i]) {
        ++same[A[i]];
      }
    }

    for (int i = 0; i < n; ++i) {
      if (cnt_a[i] + cnt_b[i] - same[i] == A.size()) {
        return A.size() - max(cnt_a[i], cnt_b[i]);
      }
    }

    return -1;
  }
};
// Runtime: 128 ms, faster than 39.40%
// Memory Usage: 19.2 MB, less than 16.67%

class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int n = A.size();
    for (int i = 0, a = 0, b = 0; i < n && (A[i] == A[0] || B[i] == A[0]);
         ++i) {
      if (A[i] != A[0]) {
        ++a;
      }

      if (B[i] != A[0]) {
        ++b;
      }

      if (i == n - 1) {
        return min(a, b);
      }
    }

    for (int i = 0, a = 0, b = 0; i < n && (A[i] == B[0] || B[i] == B[0]);
         ++i) {
      if (A[i] != B[0]) {
        ++a;
      }

      if (B[i] != B[0]) {
        ++b;
      }

      if (i == n - 1) {
        return min(a, b);
      }
    }

    return -1;
  }
};
// Runtime: 128 ms, faster than 39.40%
// Memory Usage: 19.1 MB, less than 83.33%

class Solution {
  void cnt(vector<int>& V, vector<int>& res) {
    for (auto n : V) {
      ++res[n];
    }
  }

  void find(vector<int>& v, pair<int, int>& p) {
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] > p.second) {
        p.first = i;
        p.second = v[i];
      }
    }
  }

 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    vector<int> a(7);
    vector<int> b(7);

    cnt(A, a);
    cnt(B, b);

    pair<int, int> mx_a{-1, 0};
    pair<int, int> mx_b{-1, 0};

    find(a, mx_a);
    find(b, mx_b);

    if (mx_a.second < mx_b.second) {
      swap(mx_a, mx_b);
      swap(A, B);
    }

    int ans = 0;

    for (int i = 0; i < A.size(); ++i) {
      if (A[i] != mx_a.first && B[i] != mx_a.first) {
        ans = -1;
        break;
      } else if (A[i] != mx_a.first && B[i] == mx_a.first) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 124 ms, faster than 63.10%
// Memory Usage: 19.1 MB, less than 83.33%