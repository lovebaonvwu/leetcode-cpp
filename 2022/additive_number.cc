class Solution {
 public:
  bool isAdditiveNumber(string num) {
    vector<long long> t;

    return dfs(num, 0, t);
  }

  bool dfs(string& s, int i, vector<long long>& t) {
    if (i == s.size() && t.size() > 2) {
      return true;
    }

    for (int j = 1; j + i <= s.size() && j <= 17; ++j) {
      string ns = s.substr(i, j);
      if (ns.size() > 1 && ns[0] == '0') {
        return false;
      }

      long long n = stoll(ns);
      if (n > LONG_MAX) {
        return false;
      }

      if (t.size() < 2 || n == t[t.size() - 2] + t.back()) {
        t.push_back(n);
        if (dfs(s, i + j, t)) {
          return true;
        }
        t.pop_back();
      } else if (n > t[t.size() - 2] + t.back()) {
        return false;
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 36.47%
// Memory Usage: 6.2 MB, less than 53.57%
// 2022.7.7 at 奥盛大厦