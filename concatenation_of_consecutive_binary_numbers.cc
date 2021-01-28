class Solution {
 public:
  int concatenatedBinary(int n) {
    int ans = 0;

    for (int i = 1; i <= n; ++i) {
      int x = i;

      stack<int> stk;
      while (x > 0) {
        stk.push(x % 2);
        x /= 2;
      }

      while (!stk.empty()) {
        ans = ans * 2 + stk.top();
        stk.pop();

        ans %= 1000000007;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int concatenatedBinary(int n) {
    long ans = 0;
    const int mod = 1000000007;

    for (int i = 1; i <= n; ++i) {
      int x = i, len = 0;

      while (x > 0) {
        ++len;
        x /= 2;
      }

      ans = ((ans << len) % mod + i) % mod;
    }

    return ans;
  }
};
// Runtime: 40 ms, faster than 85.72%
// Memory Usage: 5.8 MB, less than 99.39%

class Solution {
 public:
  int concatenatedBinary(int n) {
    long ans = 0;
    const int mod = 1000000007;

    for (int i = 1; i <= n; ++i) {
      int x = i, len = 0;

      while (x > 0) {
        ++len;
        x /= 2;
      }

      ans = (ans << len) % mod + i;
    }

    return ans % mod;
  }
};
// Runtime: 40 ms, faster than 85.72%
// Memory Usage: 5.8 MB, less than 99.39%

class Solution {
 public:
  int concatenatedBinary(int n) {
    long ans = 0;
    const int mod = 1000000007;

    for (int i = 1; i <= n; ++i) {
      int x = i, len = 0;

      while (x > 0) {
        ++len;
        x /= 2;
      }

      ans = ((ans << len) | i) % mod;
    }

    return ans % mod;
  }
};
// Runtime: 76 ms, faster than 70.36%
// Memory Usage: 5.9 MB, less than 99.39%

class Solution {
 public:
  int concatenatedBinary(int n) {
    long ans = 0;
    const int mod = 1000000007;

    for (int i = 1; i <= n; ++i) {
      int x = i, len = 0;

      while (x > 0) {
        ++len;
        x /= 2;
      }

      ans = ((ans << len) + i) % mod;
    }

    return ans % mod;
  }
};
// Runtime: 56 ms, faster than 77.43%
// Memory Usage: 5.9 MB, less than 98.32%