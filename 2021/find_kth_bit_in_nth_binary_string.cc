class Solution {
 public:
  char findKthBit(int n, int k) {
    for (int i = 1, cnt = 0; i <= n; ++i) {
      cnt = cnt * 2 + 1;

      if (cnt >= k - 1) {
        n = i;
        break;
      }
    }

    return dfs(n)[k - 1];
  }

  void invert(string& s) {
    for (auto& c : s) {
      c = c == '0' ? '1' : '0';
    }
  }

  string dfs(int n) {
    if (n == 0) {
      return "0";
    }

    string s = dfs(n - 1);
    string res = s;

    invert(s);
    reverse(s.begin(), s.end());

    return res + "1" + s;
  }
};
// Runtime: 256 ms, faster than 16.67%
// Memory Usage: 91.3 MB, less than 16.67%

class Solution {
 public:
  char findKthBit(int n, int k) {
    string s = "0";

    for (int i = 1; i <= n; ++i) {
      if (k <= s.size()) {
        return s[k - 1];
      }

      string ts = s;
      for (auto& c : ts) {
        c = c == '0' ? '1' : '0';
      }

      reverse(ts.begin(), ts.end());

      s += "1" + ts;
    }

    return '0';
  }
};
// Runtime: 120 ms, faster than 66.67%
// Memory Usage: 38.4 MB, less than 66.67%