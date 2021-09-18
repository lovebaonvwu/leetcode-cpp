class Solution {
  vector<string> ans;

 public:
  vector<string> addOperators(string num, int target) {
    dfs(num, target, 0, "", 0, 0);

    return ans;
  }

  void dfs(string& num,
           int target,
           int pos,
           const string& exp,
           int prev,
           int cur) {
    if (pos == num.size()) {
      if (cur == target) {
        ans.push_back(exp);
      }

      return;
    }

    for (int i = 1; i <= num.size() - pos; ++i) {
      string s = num.substr(pos, i);

      if (s.size() > 1 && s[0] == '0') {
        break;
      }

      long n = std::stol(s);
      if (n > INT_MAX) {
        break;
      }

      if (pos == 0) {
        dfs(num, target, pos + i, s, n, n);
        continue;
      }

      dfs(num, target, pos + i, exp + '+' + s, n, cur + n);
      dfs(num, target, pos + i, exp + '-' + s, -n, cur - n);
      dfs(num, target, pos + i, exp + '*' + s, prev * n, cur - prev + prev * n);
    }
  }
};
// Runtime: 802 ms, faster than 5.04%
// Memory Usage: 95.3 MB, less than 12.67%
// 2021.9.18 at 茗筑美嘉