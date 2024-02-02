class Solution {
  bool isNumber(const string& s) {
    int i = 0;
    while (i < s.size()) {
      if (!isdigit(s[i]))
        return false;
      ++i;
    }

    return true;
  }

 public:
  vector<int> diffWaysToCompute(string expression) {
    function<vector<int>(const string&)> dfs =
        [&](const string& s) -> vector<int> {
      if (isNumber(s)) {
        return {stoi(s)};
      }

      vector<int> left;
      vector<int> right;
      vector<int> ret;

      int n = s.size();
      for (int i = 0; i < n; ++i) {
        if (s[i] == '*' || s[i] == '+' || s[i] == '-') {
          left = dfs(s.substr(0, i));
          right = dfs(s.substr(i + 1));
        }

        for (auto l : left) {
          for (auto r : right) {
            if (s[i] == '*') {
              ret.push_back(l * r);
            } else if (s[i] == '+') {
              ret.push_back(l + r);
            } else if (s[i] == '-') {
              ret.push_back(l - r);
            }
          }
        }
      }

      return ret;
    };

    vector<int> ans = dfs(expression);

    return ans;
  }
};
// 8 ms
// 13.92 MB