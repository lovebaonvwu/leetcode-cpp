class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < (i == 0 ? n : 1); ++j) {
        vector<int> tmp;

        while (i < m && j < n) {
          tmp.push_back(mat[i++][j++]);
        }

        sort(tmp.begin(), tmp.end());

        while (i && j) {
          mat[--i][--j] = tmp.back();
          tmp.pop_back();
        }
      }
    }

    return mat;
  }
};
// Runtime: 24 ms, faster than 98.94%
// Memory Usage: 11.1 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    for (int i = m - 1, j = 0; i >= 0; --i) {
      vector<int> tmp;
      tmp.push_back(mat[i][j]);

      int a = i, b = j;
      while (a + 1 < m && b + 1 < n) {
        tmp.push_back(mat[a + 1][b + 1]);
        ++a;
        ++b;
      }

      sort(tmp.begin(), tmp.end());

      a = i, b = j;
      int c = 0;
      mat[a][b] = tmp[c++];

      while (a + 1 < m && b + 1 < n) {
        mat[a + 1][b + 1] = tmp[c++];
        ++a;
        ++b;
      }
    }

    for (int i = 0, j = 0; j < n; ++j) {
      vector<int> tmp;
      tmp.push_back(mat[i][j]);

      int a = i, b = j;
      while (a + 1 < m && b + 1 < n) {
        tmp.push_back(mat[a + 1][b + 1]);
        ++a;
        ++b;
      }

      sort(tmp.begin(), tmp.end());

      a = i, b = j;
      int c = 0;

      mat[a][b] = tmp[c++];

      while (a + 1 < m && b + 1 < n) {
        mat[a + 1][b + 1] = tmp[c++];
        ++a;
        ++b;
      }
    }

    return mat;
  }
};
// Runtime: 28 ms, faster than 90.41%
// Memory Usage: 11.2 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    unordered_map<int, priority_queue<int>> mp;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        mp[i - j].push(mat[i][j]);
      }
    }

    for (int i = m - 1; i >= 0; --i) {
      for (int j = 0; j < n; ++j) {
        mat[i][j] = mp[i - j].top();
        mp[i - j].pop();
      }
    }

    return mat;
  }
};
// Runtime: 32 ms, faster than 71.33%
// Memory Usage: 11.2 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    for (int k = m - 1; k >= 0; --k)
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n - 1; ++j) {
          if (mat[i][j] > mat[i + 1][j + 1]) {
            swap(mat[i][j], mat[i + 1][j + 1]);
          }
        }
      }

    return mat;
  }
};
// Runtime: 32 ms, faster than 71.33%
// Memory Usage: 10.5 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    for (int k = 0; k < m; ++k)
      for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
          if (mat[i][j] > mat[i + 1][j + 1]) {
            swap(mat[i][j], mat[i + 1][j + 1]);
          }
        }
      }

    return mat;
  }
};
// Runtime: 40 ms, faster than 47.85%
// Memory Usage: 10.4 MB, less than 100.00%