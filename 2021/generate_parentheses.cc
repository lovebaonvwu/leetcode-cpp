class Solution {
  vector<string> ans;

 public:
  vector<string> generateParenthesis(int n) {
    dfs("", n, 0);

    return ans;
  }

  void dfs(string p, int l, int r) {
    if (l == 0 && r == 0) {
      ans.push_back(p);
      return;
    }

    if (l > 0) {
      dfs(p + '(', l - 1, r + 1);
    }

    if (r > 0) {
      dfs(p + ')', l, r - 1);
    }
  }
};
// Runtime: 4 ms, faster than 88.17%
// Memory Usage: 15.4 MB, less than 79.34%

class Solution {
  vector<string> ans;

 public:
  vector<string> generateParenthesis(int n) {
    dfs("", n, n);

    return ans;
  }

  void dfs(string p, int l, int r) {
    if (l > r) {
      return;
    }

    if (l > 0) {
      dfs(p + '(', l - 1, r);
    }

    if (r > 0) {
      dfs(p + ')', l, r - 1);
    }

    if (l == 0 && r == 0) {
      ans.push_back(p);
      return;
    }
  }
};
// Runtime: 4 ms, faster than 88.17%
// Memory Usage: 15.4 MB, less than 78.51%