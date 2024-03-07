class Solution {
  bool isPrime(int n) {
    if (n < 2)
      return false;

    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0)
        return false;
    }

    return true;
  }

 public:
  int mostFrequentPrime(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    unordered_map<int, int> cnt;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int dy = -1; dy <= 1; ++dy) {
          for (int dx = -1; dx <= 1; ++dx) {
            if (dy == 0 && dx == 0) {
              continue;
            }

            int val = mat[i][j];
            int y = i + dy;
            int x = j + dx;
            while (y >= 0 && y < m && x >= 0 && x < n) {
              val = val * 10 + mat[y][x];

              if (val > 10 && isPrime(val)) {
                ++cnt[val];
              }

              y += dy;
              x += dx;
            }
          }
        }
      }
    }

    int ans = -1;
    int max_freq = 0;
    for (auto [k, v] : cnt) {
      if (v > max_freq) {
        ans = k;
        max_freq = v;
      } else if (v == max_freq) {
        ans = max(ans, k);
      }
    }

    return ans;
  }
};
// 4 ms
// 31.30 MB

class Solution {
  bool isPrime(int n) {
    if (n < 2)
      return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }

 public:
  int mostFrequentPrime(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    unordered_map<int, int> cnt;

    function<void(int, int, int, int, int)> dfs = [&](int i, int j, int dy,
                                                      int dx, int val) -> void {
      if (val > 10 && isPrime(val)) {
        ++cnt[val];
      }

      int y = i + dy;
      int x = j + dx;

      if (y < 0 || y == m || x < 0 || x == n) {
        return;
      }

      dfs(y, x, dy, dx, val * 10 + mat[y][x]);
    };

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int y = -1; y <= 1; ++y) {
          for (int x = -1; x <= 1; ++x) {
            if (y == 0 && x == 0) {
              continue;
            }

            dfs(i, j, y, x, mat[i][j]);
          }
        }
      }
    }

    int ans = -1;
    int max_freq = 0;
    for (auto [k, v] : cnt) {
      if (v > max_freq) {
        ans = k;
        max_freq = v;
      } else if (v == max_freq) {
        ans = max(ans, k);
      }
    }

    return ans;
  }
};
// 19 ms
// 31.55 MB