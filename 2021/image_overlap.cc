class Solution {
  int overlapped(vector<vector<int>>& A, vector<vector<int>>& B, int i, int j) {
    int cnt = 0;

    for (int m = 0; m < A.size(); ++m) {
      for (int n = 0; n < A[0].size(); ++n) {
        if (m - i >= 0 && m - i < A.size() && n - j >= 0 &&
            n - j < A[0].size() && A[m - i][n - j] == 1 &&
            A[m - i][n - j] == B[m][n]) {
          ++cnt;
        }
      }
    }

    return cnt;
  }

  vector<vector<int>> seen;
  int ans = 0;

 public:
  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    seen = vector<vector<int>>(A.size() * 2, vector<int>(A[0].size() * 2));
    dfs(A, B, 0, 0);

    return ans;
  }

  void dfs(vector<vector<int>> A, vector<vector<int>>& B, int i, int j) {
    if (abs(i) >= A.size() || abs(j) >= A[0].size()) {
      return;
    }

    if (seen[A.size() + i][A[0].size() + j]) {
      return;
    }

    ans = max(ans, overlapped(A, B, i, j));
    seen[A.size() + i][A[0].size() + j] = 1;

    dfs(A, B, i + 1, j);
    dfs(A, B, i - 1, j);
    dfs(A, B, i, j + 1);
    dfs(A, B, i, j - 1);
  }
};
// Runtime: 1872 ms, faster than 5.22%
// Memory Usage: 777.3 MB, less than 5.22%

class Solution {
 public:
  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<int> va;
    vector<int> vb;

    int n = A.size();

    for (int i = 0; i < n * n; ++i) {
      if (A[i / n][i % n] == 1) {
        va.push_back(i / n * 100 + i % n);
      }
    }

    for (int i = 0; i < n * n; ++i) {
      if (B[i / n][i % n] == 1) {
        vb.push_back(i / n * 100 + i % n);
      }
    }

    unordered_map<int, int> mp;
    for (auto a : va) {
      for (auto b : vb) {
        mp[a - b]++;
      }
    }

    int ans = 0;
    for (auto m : mp) {
      ans = max(ans, m.second);
    }

    return ans;
  }
};
// Runtime: 120 ms, faster than 50.20%
// Memory Usage: 11.8 MB, less than 34.54%