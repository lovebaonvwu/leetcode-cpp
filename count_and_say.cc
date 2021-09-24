class Solution {
 public:
  string countAndSay(int n) { return dfs(n, "1"); }

  string dfs(int n, const string& s) {
    if (n == 1) {
      return s;
    }

    string t;
    char prev = s[0];
    int cnt = 1;

    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != prev) {
        t += std::to_string(cnt) + prev;
        cnt = 1;
      } else {
        ++cnt;
      }

      prev = s[i];
    }

    t += std::to_string(cnt) + prev;

    return dfs(n - 1, t);
  }
};
// Runtime: 8 ms, faster than 71.86%
// Memory Usage: 7 MB, less than 32.91%
// 2021.9.24 at 奥盛大厦

class Solution {
 public:
  string countAndSay(int n) { return dfs(n, "1"); }

  string dfs(int n, const string& s) {
    if (n == 1) {
      return s;
    }

    string t;
    int cnt = 1;

    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        t += std::to_string(cnt) + s[i - 1];
        cnt = 1;
      } else {
        ++cnt;
      }
    }

    t += std::to_string(cnt) + s.back();

    return dfs(n - 1, t);
  }
};
// Runtime: 4 ms, faster than 88.88%
// Memory Usage: 7 MB, less than 32.91%
// 2021.9.24 at 奥盛大厦