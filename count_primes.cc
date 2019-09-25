class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }

    bool v[n];

    memset(v, true, sizeof(v));

    v[0] = false;
    v[1] = false;

    for (int i = 2; i * i < n; ++i) {
      if (v[i]) {
        for (int j = i + i; j < n; j += i) {
          v[j] = false;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i]) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 98.23%
// Memory Usage: 9.8 MB, less than 16.67%

class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }

    bool v[n];

    memset(v, true, sizeof(v));

    v[0] = false;
    v[1] = false;

    for (int i = 2; i * i < n; ++i) {
      if (v[i]) {
        for (int j = 2; j * i < n; ++j) {
          v[j * i] = false;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i]) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 98.23%
// Memory Usage: 9.9 MB, less than 16.67%

class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }

    bool v[n];

    memset(v, true, sizeof(v));

    v[0] = false;
    v[1] = false;

    for (int i = 2; i < n; ++i) {
      if (v[i]) {
        for (int j = 2; j * i < n; ++j) {
          v[j * i] = false;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i]) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 32 ms, faster than 78.78%
// Memory Usage: 10 MB, less than 16.67%

class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }

    vector<bool> v(n, true);

    v[0] = false;
    v[1] = false;

    for (int i = 2; i < n; ++i) {
      if (v[i]) {
        for (int j = 2; j * i < n; ++j) {
          v[j * i] = false;
        }
      }
    }

    return count(v.begin(), v.end(), true);
  }
};
// Runtime: 120 ms, faster than 28.51%
// Memory Usage: 8.7 MB, less than 54.17%