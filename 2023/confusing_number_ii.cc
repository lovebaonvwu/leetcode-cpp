class Solution {
  bool valid(int n) {
    int t = n;
    int m = 0;
    while (t > 0) {
      int x = t % 10;
      t /= 10;
      if (x == 2 || x == 3 || x == 4 || x == 5 || x == 7) {
        return false;
      }

      if (x == 6) {
        x = 9;
      } else if (x == 9) {
        x = 6;
      }

      m = m * 10 + x;
    }

    return m != n;
  }

 public:
  int confusingNumberII(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans += valid(i);
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
  bool valid(long long n) {
    long long t = n;
    long long m = 0;
    while (t > 0) {
      int x = t % 10;
      t /= 10;
      if (x == 2 || x == 3 || x == 4 || x == 5 || x == 7) {
        return false;
      }

      if (x == 6) {
        x = 9;
      } else if (x == 9) {
        x = 6;
      }

      m = m * 10 + x;
    }

    return m != n;
  }

  vector<int> digits{0, 1, 6, 8, 9};
  int ans = 0;

  void dfs(long long x, int n) {
    if (x > n) {
      return;
    }

    if (valid(x)) {
      ++ans;
    }

    for (auto d : digits) {
      dfs(x * 10 + d, n);
    }
  }

 public:
  int confusingNumberII(int n) {
    for (auto x : {1, 6, 8, 9}) {
      dfs(x, n);
    }
    return ans;
  }
};
// Runtime 348 ms
// Memory 6 MB
// 2023.1.28 at 奥盛大厦